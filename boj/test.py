import subprocess
import sys

for a in range(0, 20):
    for b in range(0, 20):
        for c in range(0, 20):
            for d in range(0, 20):
                for e in range(0, 20):
                    for f in range(0, 20):
                        # print(f'test: {a} {b} {c} {d} {e} {f}')
                        caseInput = f'{a} {b} {c} {d} {e} {f}'
                        complete = subprocess.run('./run.out', input=caseInput, encoding='utf-8', stdout=subprocess.PIPE)
                        a0 = complete.stdout
                        complete = subprocess.run('./run_test.out', input=caseInput, encoding='utf-8', stdout=subprocess.PIPE)
                        b0 = complete.stdout
                        a0 = int(a0); b0 = int(b0)
                        if a0 != b0:
                            print(f'case: {a} {b} {c} {d} {e}')
                            print(f'->{a0} {b0}')
                            print('loser')
                            sys.exit()
