import subprocess
import sys

for a in range(1, 1000):
    for b in range(0, 1000):
        print(f'test: {a}, {b}\n')
        for x in range(0, 138):
            caseInput = f'3\n{x}';
            x = (a*x+b)%10001
            x = (a*x+b)%10001
            caseInput = f'{caseInput}\n{x}'
            x = (a*x+b)%10001
            x = (a*x+b)%10001
            caseInput = f'{caseInput}\n{x}'
            complete = subprocess.run('./run.out', input=caseInput, encoding='utf-8', stdout=subprocess.PIPE)
            a0, b0 = complete.stdout.split()
            a0 = int(a0); b0 = int(b0)
            if f'{a} {b}' != f'{a0} {b0}':
                print(f';;{a} {b}')
                print(f'->{a0} {b0}')
                print('loser')
                sys.exit()
