/**
* Copyright (c) 2017 Carolina Cloud Exchange, LLC
*
* This Source Code Form is subject to the terms of the Mozilla Public License,
* v. 2.0. If a copy of the MPL was not distributed with this file, You can
* obtain one at https://mozilla.org/MPL/2.0/.
*
* This Source Code Form is “Incompatible With Secondary Licenses”, as defined
* by the Mozilla Public License, v. 2.0.
*
* Software distributed under the License is distributed on an "AS IS" basis,
* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for
* the specific language governing rights and limitations under the License.
*/

#include <iostream>
#include "catalyst_calc.h"

int main(int argc, char *argv[])
{

	if (argc < 7)
	{
		return -1;
	}

	double cpu = std::stod(argv[1]);
	double memory = std::stod(argv[2]);
	double gpu = std::stod(argv[3]);
	double disk = std::stod(argv[4]);
	double network = std::stod(argv[5]);
	double storage = std::stod(argv[6]);

	double CWU = calcWorkUnit(cpu, memory, gpu, disk, network, storage);

	std::cout << "Work Units: " << CWU << std::endl;

	return 0;
}

/*
	Takes telemetry info and calculates an Compute Work Unit (CWU)
	cpu CPU MHz
	memory Memory average in megabytes
	gpu GPU MHz
	disk Disk I/O in Kilobytes
	network Network I/O in Kilobytes
	storage Storage average in gigabytes
	returns Calculated Work Unit
*/
double calcWorkUnit(double cpu, double memory, double gpu, double disk, double network, double storage)
{
	return (cpu / DIV_CPU) +
		   (memory / DIV_MEM) +
		   (disk / DIV_DISK) +
		   (gpu / DIV_GPU) +
		   (network / DIV_NETWORK) +
		   (storage / DIV_STORAGE);
}
