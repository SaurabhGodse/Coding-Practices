#include<iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int x = 1; x <= T; x++)
    {
        int N, M, Q;
        cin >> N >> M >> Q;
        int pages[M], readers[Q];
        int i, j;
        for(i = 0; i < M; i++)
        {
            cin >> pages[i];
        }
        // cout << "input pages for : " << x << "completed" << endl;
        for(i = 0; i < Q; i++)
        {
            cin >> readers[i];
        }
        // cout << "input readers for : " << x << "completed" << endl;
        bool isvalid[N + 1] = {0};
        
        for(i = 0; i < M; i++)
        {
                isvalid[pages[i]] = true;
        }
        long count = 0;
        
        
        for(i = 0; i < Q; i++)
        {
                // temp = 0;
                count += N / readers[i];
                // if(readers[i] == 1)
                        // count -= M;

                for(j = readers[i]; j <= N; j += readers[i])
                {
                        if(isvalid[j])
                                count--;

                        

                }
        }
        cout << "Case #" << x << ": " << count << endl;
    }

//         int isdivisible[Q][M];
//         memset(isdivisible, 0, sizeof(isdivisible));
//         for(i = 0; i < Q; i++)
//         {
//                 for(j = 0; j < M; j++)
//                 {
//                         if(pages[j] % readers[i] == 0)
//                         {
//                                 isdivisible[i][j] = 1;
//                         }
//                 }
//         }

//         long count = 0;
//         for(i = 0; i < Q; i++)
//         {
//                 count += N / readers[i];
//                 for(j = 0;)
//         }

        
//     }
    return 0;
}