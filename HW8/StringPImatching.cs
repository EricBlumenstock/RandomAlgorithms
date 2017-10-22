using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringMatching
{
    class Program
    {
        static void Main(string[] args)
        {
            string p = "aaabaaaaabaaabaaaaabaaaaba"; //ababaca
            int m = p.Length;
            int[] pi = new int[p.Length];
            int k = 0;
            int q = 1;

            while (q < m)
            {
                if (k==0 && p[k] != p[q])
                {
                    pi[q] = 0;
                    q++;
                }
                else if ( p[k] == p[q])
                {
                    k++;
                    pi[q] = k;
                    q++;
                }
                else
                {
                    k = pi[k - 1];
                }
            }

            for (int i = 0; i < pi.Length; i++)
                Console.Write(pi[i] + " ");


            Console.ReadLine();
        }
    }
}
