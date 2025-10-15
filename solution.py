import sys

def solve():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        n = int(next(it)); q = int(next(it))
        queries = []
        for i in range(q):
            x = int(next(it)); y = int(next(it))
            queries.append((x,y))

        # dp: map other_robot_pos -> min extra cost beyond base sum(|x-y|)
        dp = {0: 0}
        base = 0
        INF = 10**30
        for x,y in queries:
            base += abs(x-y)
            ndp = {}
            for p, val in dp.items():
                # Option 1: use robot at x (no extra cost). other robot remains at p
                ndp[p] = min(ndp.get(p, INF), val)
                # Option 2: use the other robot at p to move to x (cost abs(p-x) unless p==0)
                extra = val + (0 if p == 0 else abs(p - x))
                new_other = x
                ndp[new_other] = min(ndp.get(new_other, INF), extra)
            dp = ndp

        best_extra = min(dp.values()) if dp else 0
        out_lines.append(str(base + best_extra))

    sys.stdout.write("\n".join(out_lines))


if __name__ == '__main__':
    solve()
