import subprocess

def run_command(command):
    print(f"Running command: {command}")
    subprocess.run(command, shell=True, check=True)

def main():
    run_command()

if __name__ == '__main__':
    main()