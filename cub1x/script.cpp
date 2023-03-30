#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
enum Colors
{
    ORANGE = 0,
    BLUE = 1,
    WHITE = 2,
    GREEN = 3,
    RED = 4,
    YELLOW = 5
};
static const char *fwdmoves = "BDFLRUbdflru";
static const char *invmoves = "bdflruBDFLRU";
static constexpr int maxmoves = 12;
static char cube[6][2][2];
void print_cube()
{
    // face 1
    cout << " "
         << " " << cube[BLUE][0][0] << " " << cube[BLUE][0][1] << " "
         << " "
         << "\n";
    cout << " "
         << " " << cube[BLUE][1][0] << " " << cube[BLUE][1][1] << " "
         << " "
         << "\n";
    // face 0, 2, 4 and 5
    cout << cube[ORANGE][0][0] << " " << cube[ORANGE][0][1] << " ";
    cout << cube[WHITE][0][0] << " " << cube[WHITE][0][1] << " ";
    cout << cube[RED][0][0] << " " << cube[RED][0][1] << " ";
    cout << cube[YELLOW][0][0] << " " << cube[YELLOW][0][1] << " "
         << "\n";
    cout << cube[ORANGE][1][0] << " " << cube[ORANGE][1][1] << " ";
    cout << cube[WHITE][1][0] << " " << cube[WHITE][1][1] << " ";
    cout << cube[RED][1][0] << " " << cube[RED][1][1] << " ";
    cout << cube[YELLOW][1][0] << " " << cube[YELLOW][1][1] << " "
         << "\n";
    // face 3
    cout << " "
         << " " << cube[GREEN][0][0] << " " << cube[GREEN][0][1] << " "
         << " "
         << "\n";
    cout << " "
         << " " << cube[GREEN][1][0] << " " << cube[GREEN][1][1] << " "
         << " "
         << "\n";
}
void rotate_face(int i)
{
    int t0 = cube[i][0][0];
    int t1 = cube[i][0][1];
    cube[i][0][0] = cube[i][1][0];
    cube[i][0][1] = t0;
    t0 = cube[i][1][1];
    cube[i][1][1] = t1;
    cube[i][1][0] = t0;
}
void operate(char op)
{
    int t0, t1;
    switch (op)
    {
    case 'B':
        t0 = cube[0][0][0];
        t1 = cube[0][0][1];
        cube[0][0][1] = cube[5][1][1];
        cube[0][0][0] = cube[5][0][1];
        cube[5][0][1] = cube[3][1][1];
        cube[5][1][1] = cube[3][1][0];
        cube[3][1][1] = cube[4][1][0];
        cube[3][1][0] = cube[4][0][0];
        cube[4][1][0] = t0;
        cube[4][0][0] = t1;
        rotate_face(1);
        break;
    case 'D':
        t0 = cube[2][1][0];
        t1 = cube[2][1][1];
        cube[2][1][0] = cube[4][1][0];
        cube[2][1][1] = cube[4][1][1];
        cube[4][1][0] = cube[1][1][0];
        cube[4][1][1] = cube[1][1][1];
        cube[1][1][1] = cube[5][1][1];
        cube[1][1][0] = cube[5][1][0];
        cube[5][1][1] = t1;
        cube[5][1][0] = t0;
        rotate_face(3);
        break;
    case 'F':
        t0 = cube[0][1][0];
        t1 = cube[0][1][1];
        cube[0][1][1] = cube[4][0][1];
        cube[0][1][0] = cube[4][1][1];
        cube[4][0][1] = cube[3][0][0];
        cube[4][1][1] = cube[3][0][1];
        cube[3][0][0] = cube[5][1][0];
        cube[3][0][1] = cube[5][0][0];
        cube[5][1][0] = t1;
        cube[5][0][0] = t0;
        rotate_face(2);
        break;
    case 'L':
        t0 = cube[2][0][0];
        t1 = cube[2][1][0];
        cube[2][0][0] = cube[0][0][0];
        cube[2][1][0] = cube[0][1][0];
        cube[0][0][0] = cube[1][1][1];
        cube[0][1][0] = cube[1][0][1];
        cube[1][1][1] = cube[3][0][0];
        cube[1][0][1] = cube[3][1][0];
        cube[3][0][0] = t0;
        cube[3][1][0] = t1;
        rotate_face(4);
        break;
    case 'R':
        t0 = cube[0][0][1];
        t1 = cube[0][1][1];
        cube[0][1][1] = cube[2][1][1];
        cube[0][0][1] = cube[2][0][1];
        cube[2][0][1] = cube[3][0][1];
        cube[2][1][1] = cube[3][1][1];
        cube[3][1][1] = cube[1][0][0];
        cube[3][0][1] = cube[1][1][0];
        cube[1][1][0] = t0;
        cube[1][0][0] = t1;
        rotate_face(5);
        break;
    case 'U':
        t0 = cube[2][0][0];
        t1 = cube[2][0][1];
        cube[2][0][0] = cube[5][0][0];
        cube[2][0][1] = cube[5][0][1];
        cube[5][0][0] = cube[1][0][0];
        cube[5][0][1] = cube[1][0][1];
        cube[1][0][0] = cube[4][0][0];
        cube[1][0][1] = cube[4][0][1];
        cube[4][0][1] = t1;
        cube[4][0][0] = t0;
        rotate_face(0);
        break;
    case 'b':
        for (t0 = 0; t0 < 3; t0++)
            operate('B');
        break;
    case 'd':
        for (t0 = 0; t0 < 3; t0++)
            operate('D');
        break;
    case 'f':
        for (t0 = 0; t0 < 3; t0++)
            operate('F');
        break;
    case 'l':
        for (t0 = 0; t0 < 3; t0++)
            operate('L');
        break;
    case 'r':
        for (t0 = 0; t0 < 3; t0++)
            operate('R');
        break;
    case 'u':
        for (t0 = 0; t0 < 3; t0++)
            operate('U');
        break;
    default:
        cout << "INVALID MOVE!" << endl;
        break;
    }
}
void operate(string steps)
{
    for (char s : steps)
    {
        operate(s);
        print_cube();
        cout << endl;
    }
}
bool solved()
{
    for (int f = 0; f < 6; f++)
    {
        for (int r = 0; r < 2; r++)
            for (int c = 0; c < 2; c++)
                if (cube[f][r][c] != cube[f][0][0])
                    return false;
    }
    return true;
}

constexpr int DEPTH = 12;

int stk[DEPTH + 1];
int top = 0;
void solve(int depth)
{
    if (solved() || depth == 0)
        return;
    for (int s = 0; s < 6; s++)
    {
        if (top < 0 || top > DEPTH)
            cout << "STACK IS WRONG : top = " << top << endl;
        operate(fwdmoves[s]);
        stk[top++] = s;
        if (solved())
        {
            return;
        }
        else
        {
            if (depth != 0)
            {
                solve(depth - 1);
                if (solved())
                    return;
            }
            operate(invmoves[stk[--top]]); // backtrack
        }
    }
}
int main(int argc, char **argv)
{

    char *pattern = "oobgbbwyrorgwygrwyrgwyob";
    int k = 0;
    for (int f = 0; f < 6; f++)
    {
        for (int r = 0; r < 2; r++)
            for (int c = 0; c < 2; c++)
            {
                cube[f][r][c] = pattern[k++];
            }
    }
    cout << "Initial Cube State : \n";
    print_cube();
    cout << endl;
    
    string steps = "";
        solve(DEPTH);
        for (int i = 0; i < top; i++)
        {
            steps += fwdmoves[stk[i]];
        }
    cout << "SOLUTION = " << steps << endl;
    cout << "\n\nFinal State :\n";
    print_cube();
    cout << endl;
    return 0;
}