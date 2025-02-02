import sys
import os
import time

CC = "gcc"
GCC = "g++"
CCFLAGS = ""
GCCFLAGS = ""


def speed_tests(prefix : str):
    # test all tests at "speed_tests" dir that starts with prefix and end with ".txt"
    print("Speed tests:")
    tests = [f for f in os.listdir("speed_tests") if f.startswith(prefix) and f.endswith(".txt")]
    tests.sort()

    if (len(prefix)!=0):
        print(f"Prefix set to \"{prefix}\"!")

    for test in tests:
        # check if other files called "<test>.c" and "<test>.cpp" exist
        base_name = os.path.splitext(test)[0]
        c_version = os.path.exists(f"speed_tests/{base_name}.c")
        cpp_version = os.path.exists(f"speed_tests/{base_name}.cpp")

        if not c_version or not cpp_version:
            print(f"\tTest \"{base_name}\" missing C or C++ version")
            continue

        # compile the tests
        os.system(f"{CC} {CCFLAGS} -o bin_K speed_tests/{base_name}.c -I ../build/")
        os.system(f"{GCC} {GCCFLAGS} -o bin_STD speed_tests/{base_name}.cpp")

        # for every line in {base_name}.txt, run the test that many times
        with open(f"speed_tests/{test}", "r") as f:
            print(f"\tRunning speed_tests/{base_name}:")
            for line in f:
                line = line.strip()
                if line == "":
                    continue

                # run the tests
                print(f"\t\t{line}:", end="")
                result_K = os.popen(f"time -p ./bin_K {line} 2>&1 | grep real | awk '{{print $2 \"s\"}}' | tr -d '\n';").read()
                result_STD = os.popen(f"time -p ./bin_STD {line} 2>&1 | grep real | awk '{{print $2 \"s\"}}' | tr -d '\n';").read()
                print(f"\t{result_K} - {result_STD}")
            print()
    os.system("rm bin_K bin_STD")








def valid_tests(prefix : str):
    # test all tests at "valid_tests" dir that starts with prefix and end with ".txt"
    print("Valid tests:")
    tests = [f for f in os.listdir("valid_tests") if f.startswith(prefix) and f.endswith(".txt")]
    tests.sort()

    if (len(prefix)!=0):
        print(f"Prefix set to \"{prefix}\"!")
    
    for test in tests:
        # check if other files called "<test>.c" and "<test>.cpp" exist
        base_name = os.path.splitext(test)[0]
        c_version = os.path.exists(f"valid_tests/{base_name}.c")
        cpp_version = os.path.exists(f"valid_tests/{base_name}.cpp")

        if not c_version or not cpp_version:
            print(f"\tTest \"{base_name}\" missing C and/or C++ version\n")
            continue

        # compile the tests
        os.system(f"{CC} {CCFLAGS} -o bin_K valid_tests/{base_name}.c -I ../build/")
        os.system(f"{GCC} {GCCFLAGS} -o bin_STD valid_tests/{base_name}.cpp")

        # for every line in {base_name}.txt, run the test that many times
        with open(f"valid_tests/{test}", "r") as f:
            print(f"\tRunning valid_tests/{base_name}:")
            for line in f:
                line = line.strip()
                if line == "":
                    continue

                # run the tests
                print(f"\t\t{line}:", end="")
                result_K = os.popen(f"./bin_K {line}").read()
                result_STD = os.popen(f"./bin_STD {line}").read()
                with open("result_K.txt", "w") as f1, open("result_STD.txt", "w") as f2:
                    f1.write(result_K)
                    f2.write(result_STD)
                different = os.popen("diff -qaZ result_K.txt result_STD.txt").read()

                if different:
                    print("✘ diff?[y/n]:", end="")
                    show_diff = input()
                    if show_diff == "y":
                        print(os.popen("diff -y result_K.txt result_STD.txt").read())
                else:
                    print("✔")

                os.remove("result_K.txt")
                os.remove("result_STD.txt")
            print()
    os.system("rm bin_K bin_STD")








if __name__ == '__main__':
    # check if there are any arguments
    if len(sys.argv)>1:
        if (sys.argv[1] == "-s"):
            if len(sys.argv)==3:
                speed_tests(sys.argv[2])
            else:
                speed_tests("")

        elif (sys.argv[1] == "-v"):
            if len(sys.argv)==3:
                valid_tests(sys.argv[2])
            else:
                valid_tests("")

        elif (sys.argv[1] == "-o"):
            valid_tests("")
            speed_tests("")


        else:
            valid_tests(sys.argv[1])
            speed_tests(sys.argv[1])


    else:
        # test all (speed_tests & valid_tests)
        valid_tests("")
        speed_tests("")