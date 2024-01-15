#include "io.h"
#include "graph.h"

/// <summary>
/// The main function of the program.
/// </summary>
/// <returns>Always returns 0.</returns>
int main()
{
	int noOfSamples = 0;
	int samples[seneca::MAX_NO_OF_SAMPLES] = { 0 };
	bool done = false;

	seneca::drawLine(seneca::GRAPH_WIDTH);
	seneca::drawLineWithLabel(seneca::GRAPH_WIDTH, "Welcome to SeneGraph");
	seneca::drawLine(seneca::GRAPH_WIDTH);

	while (!done)
	{
		int userChoice = seneca::menu(noOfSamples);
		switch (userChoice)
		{
		case 1:
			seneca::printMsg("Enter number of available samples: ");
			noOfSamples = seneca::getInt(1, seneca::MAX_NO_OF_SAMPLES);
			break;
		case 2:
			if (noOfSamples == 0)
			{
				seneca::printErrorMsg("Number of samples must be set first!");
			}
			else
			{
				seneca::printMsg("Please enter the sample values:\n");
				seneca::getSamples(samples, noOfSamples);
			}
			break;
		case 3:
			if (noOfSamples == 0)
			{
				seneca::printErrorMsg("Number of samples must be set first!");
			}
			else if (samples[0] == 0)
			{
				seneca::printMsg("Samples missing. Please enter the sample values.\n");
			}
			else
			{
				seneca::printGraph(samples, noOfSamples, "SeneGraph");
			}
			break;
		case 0:
			seneca::printMsg("Thank you for using SeneGraph. Bye!\n");
			done = true;
		}
	}
}
