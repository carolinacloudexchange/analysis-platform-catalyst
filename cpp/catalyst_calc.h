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

#ifndef CATALYSTCALC_CATALYSTCALC_H
#define CATALYSTCALC_CATALYSTCALC_H

#include <string>

#define DIV_CPU 7.68
#define DIV_MEM 327.68
#define DIV_DISK 10000.0
#define DIV_NETWORK 20000.0
#define DIV_GPU 465.6
#define DIV_STORAGE 16.0

double static calcWorkUnit(double cpu, double memory, double gpu, double disk, double network, double storage);

#endif //CATALYSTCALC_CATALYSTCALC_H
