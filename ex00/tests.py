#!/usr/bin/env python3
import subprocess

def run_test(input_value):
    try:
        result = subprocess.run(
            ['./convert', input_value],
            capture_output=True,
            text=True
        )
        return result.stdout.strip(), result.stderr.strip()
    except Exception as e:
        return str(e), "Error"

def main():
    test_cases = []

    # Test characters
    for i in range(128):  # ASCII range
        char = chr(i)
        if i >= 32 and i <= 126:
            test_cases.append(f"{char}")  # Printable characters with quotes
        else:
            test_cases.append(char)  # Non-printable as plain input

    # Test integers
    test_cases.extend(["0", "42", "-42", str(2**31 - 1), str(-2**31)])

    # Test floats
    test_cases.extend(["1.0f", "-2.5f", "+inf", "-inf", "nan", "3.14f", "1e10f", "-1.5e-4f"])

    # Test doubles
    test_cases.extend(["1.0", "-2.5", "+inf", "-inf", "nan", "3.14", "1e10", "-1.5e-4"])

    # Test invalid inputs
    test_cases.extend(["abc", "5.5x", "", " '", "42f", "42.42.42"])

    for test in test_cases:
        stdout, stderr = run_test(test)
        print(f"Input: {test}")
        print(f"Stdout: {stdout}")
        print(f"Stderr: {stderr}")
        print("-" * 40)

if __name__ == "__main__":
    main()