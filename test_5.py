#!/usr/bin/env python3

from itertools import permutations
import subprocess
import sys

MAX_OPERATIONS = 14
VALID_OPERATIONS = {
    "sa", "sb", "ss",
    "pa", "pb",
    "ra", "rb", "rr",
    "rra", "rrb", "rrr",
}


def swap(stack):
    if len(stack) >= 2:
        stack[0], stack[1] = stack[1], stack[0]


def push(source, destination):
    if source:
        destination.insert(0, source.pop(0))


def rotate(stack):
    if stack:
        stack.append(stack.pop(0))


def reverse_rotate(stack):
    if stack:
        stack.insert(0, stack.pop())


def execute_operation(operation, stack_a, stack_b):
    if operation == "sa":
        swap(stack_a)
    elif operation == "sb":
        swap(stack_b)
    elif operation == "ss":
        swap(stack_a)
        swap(stack_b)
    elif operation == "pa":
        push(stack_b, stack_a)
    elif operation == "pb":
        push(stack_a, stack_b)
    elif operation == "ra":
        rotate(stack_a)
    elif operation == "rb":
        rotate(stack_b)
    elif operation == "rr":
        rotate(stack_a)
        rotate(stack_b)
    elif operation == "rra":
        reverse_rotate(stack_a)
    elif operation == "rrb":
        reverse_rotate(stack_b)
    elif operation == "rrr":
        reverse_rotate(stack_a)
        reverse_rotate(stack_b)


def run_test(numbers):
    command = ["./push_swap", *map(str, numbers)]

    try:
        result = subprocess.run(
            command,
            capture_output=True,
            text=True,
            timeout=2,
        )
    except subprocess.TimeoutExpired:
        return {
            "status": "TIMEOUT",
            "operations": [],
            "error": "O programa entrou em loop ou demorou demais.",
        }

    if result.returncode != 0:
        return {
            "status": "CRASH",
            "operations": [],
            "error": result.stderr.strip(),
        }

    operations = [
        line.strip()
        for line in result.stdout.splitlines()
        if line.strip()
    ]

    invalid_operations = [
        operation
        for operation in operations
        if operation not in VALID_OPERATIONS
    ]

    if invalid_operations:
        return {
            "status": "INVALID",
            "operations": operations,
            "error": f"Operações inválidas: {invalid_operations}",
        }

    stack_a = list(numbers)
    stack_b = []

    for operation in operations:
        execute_operation(operation, stack_a, stack_b)

    is_sorted = stack_a == sorted(numbers) and not stack_b

    if not is_sorted:
        return {
            "status": "KO",
            "operations": operations,
            "stack_a": stack_a,
            "stack_b": stack_b,
        }

    if len(operations) > MAX_OPERATIONS:
        return {
            "status": "TOO_MANY",
            "operations": operations,
            "stack_a": stack_a,
            "stack_b": stack_b,
        }

    return {
        "status": "OK",
        "operations": operations,
        "stack_a": stack_a,
        "stack_b": stack_b,
    }


def main():
    total = 0
    correct = 0
    within_limit = 0
    failures = []
    worst_cases = []
    max_operations = 0

    for numbers in permutations(range(1, 6)):
        total += 1
        result = run_test(numbers)
        operation_count = len(result["operations"])

        if result["status"] in {"OK", "TOO_MANY"}:
            correct += 1

        if result["status"] == "OK":
            within_limit += 1
        else:
            failures.append((numbers, result))

        if operation_count > max_operations:
            max_operations = operation_count
            worst_cases = [(numbers, result["operations"])]
        elif operation_count == max_operations:
            worst_cases.append((numbers, result["operations"]))

    print(f"Testes executados:       {total}")
    print(f"Ordenações corretas:     {correct}/{total}")
    print(f"Com até 14 operações:    {within_limit}/{total}")
    print(f"Maior número de moves:   {max_operations}")
    print()

    if failures:
        print("FALHAS:")
        for numbers, result in failures:
            count = len(result["operations"])

            print(
                f"{numbers}: {result['status']} "
                f"({count} operações)"
            )

            if result.get("error"):
                print(f"  erro: {result['error']}")

            if result["status"] == "KO":
                print(f"  stack_a final: {result['stack_a']}")
                print(f"  stack_b final: {result['stack_b']}")

            if result["operations"]:
                print(f"  moves: {' '.join(result['operations'])}")
    else:
        print("Todos os casos passaram.")

    print()
    print("PIORES CASOS:")

    for numbers, operations in worst_cases[:10]:
        print(f"{numbers}: {len(operations)} operações")
        print(f"  {' '.join(operations)}")

    if failures:
        sys.exit(1)


if __name__ == "__main__":
    main()
