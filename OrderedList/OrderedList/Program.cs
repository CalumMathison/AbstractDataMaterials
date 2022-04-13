using System;
using System.Diagnostics;

namespace OrderedList
{
    class OrderedList
    {
        const int LISTSIZE = 10000;

        private int[] m_items;
        private int tail;

        public OrderedList()
        {
            m_items = new int[LISTSIZE];
            tail = 0;
        }

        public bool IsEmpty()
        {
            if (tail <= 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool IsFull()
        {
            if (tail >= LISTSIZE)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public int Size()
        {
            return tail;
        }

        public int Show(int index)
        {
            if (!IsEmpty())
            {
                return m_items[index];
            }
            else
            {
                Console.WriteLine("Cannot get item at index " + index + ". List is currently empty.");
                return -1;
            }
        }

        public void Add(int newItem)
        {
            m_items[tail] = newItem;
            int i = tail;

            while (i > 0)
            {
                if (m_items[i] < m_items[i-1])
                {
                    int x = m_items[i - 1];
                    m_items[i - 1] = m_items[i];
                    m_items[i] = x;
                    i--;
                }
                else
                {
                    i = 0;
                }
            }

            tail++;
        }

        public int Remove(int index)
        {
            int tmp = m_items[index];
            int i = index;

            while (i < tail - 1)
            {
                m_items[index] = m_items[index + 1];
                i++;
            }

            tail--;
            return tmp;
        }

        public int Search(int searchValue)
        {
            int index = 0;

            while (index < tail)
            {
                if (m_items[index] == searchValue)
                {
                    return index;
                }
                else
                {
                    if (m_items[index] > searchValue)
                    {
                        index = tail;
                    }
                    else
                    {
                        index++;
                    }
                }
            }

            return -1;
        }

        public int linearSearch(int searchValue)
        {
            int curr = 0;

            // while current position < tail
            while (curr < tail)
            {
                // if value at current position equals searchvalue
                if (m_items[curr] == searchValue)
                    // return current position
                    return curr;
                else
                    // if value at current position is greater than searchvalue
                    if (m_items[curr] > searchValue)
                    // skip to end
                    break;

                curr++;
            }

            return -1;
        }

        public int binarySearch(int searchvalue)
        // Look for the value given in the list, return the index if it is found, or -1 if it can't find it
        {
            int bottom, top, pivot;
            bool found;

            bottom = 0;
            top = tail - 1;
            found = false;

            do
            {
                pivot = (bottom + top) / 2;

                if (m_items[pivot] == searchvalue)
                {
                    found = true;
                }
                else if (m_items[pivot] < searchvalue)
                {
                    bottom = pivot + 1;
                }
                else
                {
                    top = pivot - 1;
                }
            }
            while (!found && (top >= bottom));

            if (found)
            {
                return pivot;
            }
            else
            {
                return -1;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Create a new list object
            const int SEARCHCOUNT = 5000;
            OrderedList testlist;
            testlist = new OrderedList();
            Random rng = new Random();
            Stopwatch allSearches = new Stopwatch();
            float linearSearch, binarySearch, candidateGeneration;
            int[] searchData = new int[SEARCHCOUNT];
            int searchCandidate, searchResult;

            // Fill it with random values
            while (!testlist.IsFull())
            {
                testlist.Add(rng.Next(0, SEARCHCOUNT));
            }

            //// Display the contents
            //Console.BackgroundColor = ConsoleColor.Green;
            //Console.ForegroundColor = ConsoleColor.Black;
            //Console.WriteLine("index\t+0\t+1\t+2\t+3");
            //Console.ResetColor();

            //for (int i = 0; i < testlist.Size(); i += 4)
            //{
            //    Console.BackgroundColor = ConsoleColor.Green;
            //    Console.ForegroundColor = ConsoleColor.White;
            //    Console.Write(i);
            //    Console.ResetColor();
            //    Console.Write("\t" + testlist.Show(i) + "\t" + testlist.Show(i + 1) + "\t" + testlist.Show(i + 2) + "\t" + testlist.Show(i + 3) + "\n");
            //}

            // Perform some random searches


            allSearches.Start();
            for (int i = 0; i < SEARCHCOUNT; i++)
            {
                searchData[i] = rng.Next(0, SEARCHCOUNT);
            }
            allSearches.Stop();
            candidateGeneration = allSearches.ElapsedMilliseconds;
            allSearches.Reset();

            // Perform some random searches
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("\nLinear Searching for:");
            allSearches.Start();
            for (int i = 0; i < SEARCHCOUNT; i++)
            {
                searchCandidate = rng.Next(0, SEARCHCOUNT);
                searchResult = testlist.linearSearch(searchData[i]);
                Console.WriteLine("" + i + ":\t" + searchData[i] + ": " + ((searchResult != -1) ? ("Found at: " + searchResult) : ("Not Found")));
            }
            allSearches.Stop();

            linearSearch = allSearches.ElapsedMilliseconds;

            allSearches.Reset();
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("\nBinary Searching for:");
            allSearches.Start();
            for (int i = 0; i < SEARCHCOUNT; i++)
            {
               searchCandidate = rng.Next(0, SEARCHCOUNT);
                searchResult = testlist.binarySearch(searchData[i]);
                Console.WriteLine("" + i + ":\t" + searchData[i] + ": " + ((searchResult != -1) ? ("Found at: " + searchResult) : ("Not Found")));
            }
            allSearches.Stop();

            binarySearch = allSearches.ElapsedMilliseconds;

            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("\nCandidate Generation took: " + candidateGeneration + "ms for " + SEARCHCOUNT + " searches");
            Console.WriteLine("Time per candidate: ~" + candidateGeneration / (float)SEARCHCOUNT + "ms inc overheads");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("\nLinear Searching took: " + linearSearch + "ms for " + SEARCHCOUNT + " searches");
            Console.WriteLine("Time per search: ~" + linearSearch / (float)SEARCHCOUNT + "ms inc overheads");
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("\nBinary Searching took: " + binarySearch + "ms for " + SEARCHCOUNT + " searches");
            Console.WriteLine("Time per search: ~" + binarySearch / (float)SEARCHCOUNT + "ms inc overheads");
            Console.ReadKey();

        }
    }
}
