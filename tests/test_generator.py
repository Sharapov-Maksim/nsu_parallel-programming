
import random
import argparse

def generate_random_integers(count):
    """Generate a list of random integers."""
    return [random.randint(-1000000, 1000000) for _ in range(count)]

def write_to_file(filename, integers):
    """Write the list of integers to a file."""
    with open(filename, 'w') as f:
        f.write(f"{len(integers)}\n")
        for number in integers:
            f.write(f"{number} ")
        f.write("\n")

def main():
    # Set up argument parsing
    parser = argparse.ArgumentParser(description="Generate 2^N random integers and write them to a file.")
    parser.add_argument("N", type=int, help="The exponent N for generating 2^N random integers.")
    parser.add_argument("filename", type=str, help="The output filename to write the integers to.")
    parser.add_argument("genexpected", type=bool, help="Generate additional file with sorted integers.", default=True)
    
    args = parser.parse_args()

    # Calculate the number of integers to generate
    count = 2 ** args.N

    # Generate random integers
    random_integers = generate_random_integers(count)

    # Write the integers to the specified file
    write_to_file(args.filename, random_integers)
    if (bool(args.genexpected)):
        write_to_file(args.filename + ".expected", sorted(random_integers))

    print(f"Generated {count} random integers and wrote them to {args.filename}.")

if __name__ == "__main__":
    main()

