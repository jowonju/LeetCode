class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //x check
        for(int y = 0; y < 9; y++)
        {
            unordered_map<char, int> m;
            for(int x = 0; x < 9; x++)
            {   
                if(board[y][x] == '.')
                    continue;

                m[board[y][x]]++;
                
                if(m[board[y][x]] > 1)
                    return false;
            }
            m.clear();
        }
        
        //y check
        for(int x = 0; x < 9; x++)
        {
            unordered_map<char, int> m;
            for(int y = 0; y < 9; y++)
            {
                if(board[y][x] == '.')
                    continue;
                
       
                m[board[y][x]]++;
                
                if(m[board[y][x]] > 1)
                     return false;
                     
            }
            m.clear();
        }
        
        //grid check
        int xAdd = 0;
        int yAdd = 0;
        int count = 0;
     
        while(count != 9)
        {
            if(xAdd == 9)
                xAdd = 0;
                
            unordered_map<char, int> m;
            for(int y = yAdd; y < yAdd + 3; y++)
            {
                for(int x = xAdd; x < xAdd + 3; x++)
                {    
                    if(board[y][x] == '.')
                        continue;

                    m[board[y][x]]++;
                    
                    if(m[board[y][x]] > 1)
                        return false;
                }
            }
            count++;
            m.clear();
            xAdd += 3;
            
            if(count % 3 == 0)
                yAdd +=3;
        }
        
        return true;
        
    }
};