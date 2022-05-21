import subprocess

if __name__ == "__main__":
    file_data = open("task_onezero/test_data.txt")
    file_results = open("task_onezero/test_results.txt")

    for result_line in file_results.readline():
        data_line1 = file_data.readline()
        data_line2 = file_data.readline()

        # args_line = "<<EOF\n" + data_line1[:-3] + " " + data_line2 + "EOF"
        output = subprocess.check_output(["python3","task_onezero/python/main.py", '''<<EOF\none one\nEOF'''])
        print(output)

    file_data.close()
    file_results.close()