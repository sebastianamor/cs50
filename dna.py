import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    
    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)
    
    str_sequences = list(reader.fieldnames[1:]) if database else []
    
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        dna_sequence = file.read().strip()
    
    # TODO: Find longest match of each STR in DNA sequence
    str_counts = {}
    for str_seq in str_sequences:
        str_counts[str_seq] = longest_match(dna_sequence, str_seq)
    
    # TODO: 
    for person in database:
        match = True
        for str_seq in str_sequences:
            if int(person[str_seq]) != str_counts[str_seq]:
                match = False
                break
        
        if match:
            print(person['name'])
            return
    
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence) 

   
    for i in range(sequence_length):

        
        count = 0
        while True:

           
            start = i + count * subsequence_length
            end = start + subsequence_length

          
            if sequence[start:end] == subsequence:
                count += 1
            
           
            else:
                break
        
        
        longest_run = max(longest_run, count)

  
    return longest_run


if __name__ == "__main__":
    main()