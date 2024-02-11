class solution
{
public:
    bool validskudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> row;
        unordered_map<char, int> column;
        unordered_map<char, int> threebox;
        int i;
        int j;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (row.find(board[i][j]) != row.end())
                        return false;
                    row[board[i][j]]++;
                }

                if (board[j][i] != '.')
                {
                    if (column.find(board[j][i]) != column.end())
                        return false;
                    column[board[j][i]]++;
                }
            }
            row.clear();
            column.clear();
        }
        int x;
        int y;
        for (i = 0; i < 9; i += 3)
        {
            for (j = 0; j < 9; j += 3)
            {
                for (x = i; x < i + 3; x++)
                {
                    for (y = j; y < j + 3; y++)
                    {
                        if (board[x][y] != '.')
                        {
                            if (threebox.find(board[x][y] != threebox.end()))
                                return false;
                            threebox[board[x][y]]++
                        }
                    }
                }
                threebox.clear();
            }
        }
    }
}