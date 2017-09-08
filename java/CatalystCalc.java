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

package com.carolinacloudx.analysis.catalyst;

@SuppressWarnings("unused")
public class CatalystCalc
{
	private static double DIV_CPU = 7.68;
	private static double DIV_MEM = 327.68;
	private static double DIV_DISK = 10000.0;
	private static double DIV_NETWORK = 20000.0;
	private static double DIV_GPU = 465.6;
	private static double DIV_STORAGE = 16.0;

	/**
	 * Takes telemetry info and calculates a Workload Consumption Unit (WCU)
	 * @param cpu CPU MHz
	 * @param memory Memory average in megabytes
	 * @param gpu GPU MHz
	 * @param disk Disk I/O in Kilobytes
	 * @param network Network I/O in Kilobytes
	 * @param storage Storage average in gigabytes
	 * @return Calculated Work Unit
	 */
	public static double calcWorkUnit(double cpu, double memory, double gpu, double disk, double network, double storage)
	{
		return (cpu / DIV_CPU) + (memory / DIV_MEM) + (disk / DIV_DISK) + (gpu / DIV_GPU) + (network / DIV_NETWORK) + (storage / DIV_STORAGE);
	}

	public static void main(String[] args)
	{
		if(args.length != 6)
		{
			return;
		}

		double cpu = Double.parseDouble(args[1]);
		double memory = Double.parseDouble(args[1]);
		double gpu = Double.parseDouble(args[1]);
		double disk = Double.parseDouble(args[1]);
		double network = Double.parseDouble(args[1]);
		double storage = Double.parseDouble(args[1]);

		double CWU = calcWorkUnit(cpu, memory, gpu, disk, network, storage);

		System.out.println("Work Units: " + CWU);
	}

}
