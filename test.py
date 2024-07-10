import subprocess

def run_program(input_data):
    process = subprocess.Popen(
        [r'C:\Users\Vasenka\source\repos\Assignment5_Intepreter\x64\Debug\Assignment5_Intepreter.exe'], 
        stdin=subprocess.PIPE, 
        stdout=subprocess.PIPE, 
        stderr=subprocess.PIPE, 
        text=True
    )
    stdout, stderr = process.communicate(input_data)
    return stdout.strip(), stderr.strip()

def test_program():
    tests = [
        {
            "input": "3 + 5\nexit\n",
            "expected_output": "> < 8\n>"
        },
        {
            "input": "var x = 10\nexit\n",
            "expected_output": "> >"
        },
        {
            "input": "var x = 10\nx\nexit\n",
            "expected_output": "> > < 10\n>"
        },
        {
            "input": "var x = 10\nx + 2\nexit\n",
            "expected_output": "> > < 12\n>"
        },
        {
            "input": "2 * (3 + 4)\nexit\n",
            "expected_output": "> < 14\n>"
        },
        {
            "input": "max(2, 7)\nexit\n",
            "expected_output": "> < 7\n>"
        },
        {
            "input": "min(2, 7)\nexit\n",
            "expected_output": "> < 2\n>"
        },
        {
            "input": "2 * pow(2, 3)\nexit\n",
            "expected_output": "> < 16\n>"
        },
        {
            "input": "abs(-5)\nexit\n",
            "expected_output": "> < 5\n>"
        },
        {
            "input": "abs(5)\nexit\n",
            "expected_output": "> < 5\n>"
        },
        {
            "input": "max(min(2, 8), 1)\nexit\n",
            "expected_output": "> < 2\n>"
        }
        
    ]
    
    for test in tests:
        input_data = test["input"]
        expected_output = test["expected_output"]
        
        output, error = run_program(input_data)
        
        if error:
            print(f"Test failed for input:\n{input_data}")
            print(f"Error:\n{error}")
        elif output.strip() != expected_output:
            print(f"Test failed for input:\n{input_data}")
            print(f"Expected:\n{expected_output}")
            print(f"Got:\n{output}")
        else:
            print(f"Test passed for input:\n{input_data}")

if __name__ == "__main__":
    test_program()
