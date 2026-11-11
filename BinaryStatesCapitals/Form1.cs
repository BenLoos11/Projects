//Prologue

using System;
using System.Windows.Forms;

namespace BinaryStatesCapitals
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();

        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            String[] state = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };
            String[] capital = { "Montgomery", "Juneau", "Phoenix", "Little Rock", "Sacramento", "Denver", "Hartford", "Dover", "Tallahassee", "Atlanta", "Honolulu", "Boise", "Springfield", "Indianapolis", "Des Moines", "Topeka", "Frankfort", "Baton Rouge", "Augusta", "Annapolis", "Boston", "Lansing", "St. Paul", "Jackson", "Jefferson City", "Helena", "Lincoln", "Carson City", "Concord", "Trenton", "Santa Fe", "Albany", "Raleigh", "Bismarck", "Columbus", "Oklahoma City", "Salem", "Harrisburg", "Providence", "Columbia", "Pierre", "Nashville", "Austin", "Salt Lake City", "Montpellier", "Richmond", "Olympia", "Charleston", "Madison", "Cheyenne" };
            String detail = "Not Found";
            int low = 0;
            int high = state.GetUpperBound(0);
            int middle;
            bool done = false;

            //Preprocessing
            rtbOut.Clear();
            rtbOut.AppendText("       States and Capitals" + "\n");
            rtbOut.AppendText("         Search Program" + "\n\n");
            rtbOut.AppendText("State             Capital" + "\n");

            //Input
            string search = txtSearch.Text;
            search = search.ToUpper();

            while (low <= high && !done) {
                middle = ((low + high) / 2);

                if (search == state[middle].ToUpper())
                {
                    detail = state[middle].PadRight(15) + capital[middle] + "\n";
                    done = true;
                }
                else
                {
                    if (String.Compare(search, state[middle].ToUpper(), true) < 0)
                     {
                        high = middle - 1;
                     }
                     else
                    {
                        low = middle + 1;
                    }
                }

            }
                rtbOut.AppendText(detail);

        }
    }
}
