"""
Given a matrix with each cell containing each number of candies,
and a constraint that you can move only right or down, from the
top left corner to the bottom right corner, find the path that
gets you maximum candies.

"""

def max_candies(a, i=0, j=0, visited={}):
    r = len(a)
    c = len(a[0])
    if not visited:
        for k in range(r):
            visited[k] = {}
            for l in range(c):
                visited[k][l] = -1
    if i == r - 1 and j == c - 1:
        return a[i][j]

    if i >= r or j >= c:
        return 0

    if visited[i][j] != -1:
        return visited[i][j]

    r_i, r_j = i, j + 1
    if r_i < r and r_j < c:
        visited[r_i][r_j] = max_candies(a, i=r_i, j=r_j, visited=visited)

    d_i, d_j = i + 1, j
    if d_i < r and d_j < c:
        visited[d_i][d_j] = max_candies(a, i=d_i, j=d_j, visited=visited)

    visited[i][j] = a[i][j] + max(0 if r_i >= r or r_j >= c else visited[r_i][r_j],
                                  0 if d_i >= r or d_j >= c else visited[d_i][d_j])

    return visited[i][j]

def main():
    r, c = map(lambda x: int(x), raw_input().split(' '))
    i, j = (0, 0)
    mat  = []
    while i < r:
        row = map(lambda x: int(x), raw_input().split(' '))
        mat.append(row)
        i += 1

    print max_candies(mat)

if __name__ == '__main__':
    main()

