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

package main


import (
	"os"
	"strconv"
	"fmt"
)

var (
	DIV_CPU float64 = 7.68
	DIV_MEM float64 = 327.68
	DIV_DISK float64 = 10000.0
	DIV_NETWORK float64 = 20000.0
	DIV_GPU float64 = 465.6
	DIV_STORAGE float64 = 16.0
)

func main() {

	if len(os.Args) < 7 {
		return
	}

	cpu, err := strconv.ParseFloat( os.Args[1], 64)
	memory, err := strconv.ParseFloat(os.Args[2], 64)
	gpu, err := strconv.ParseFloat(os.Args[3], 64)
	disk, err := strconv.ParseFloat(os.Args[4], 64)
	network, err := strconv.ParseFloat(os.Args[5], 64)
	storage, err := strconv.ParseFloat(os.Args[6], 64)

	if err != nil {}

	CWU := calcWorkUnit(cpu, memory, gpu, disk, network, storage)

	fmt.Println("Work Units: ", CWU)

}


/*
	Takes telemetry info and calculates a Work Load Consumption (WLC)
	cpu CPU MHz
	memory Memory average in megabytes
	gpu GPU MHz
	disk Disk I/O in Kilobytes
	network Network I/O in Kilobytes
	storage Storage average in gigabytes
	returns Calculated Work Unit
*/
func calcWorkUnit(cpu float64, memory float64, gpu float64, disk float64, network float64, storage float64) float64 {
	return (cpu / DIV_CPU) +
		(memory / DIV_MEM) +
		(disk / DIV_DISK) +
		(gpu / DIV_GPU) +
		(network / DIV_NETWORK) +
		(storage / DIV_STORAGE)
}
