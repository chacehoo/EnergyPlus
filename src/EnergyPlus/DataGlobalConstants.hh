// EnergyPlus, Copyright (c) 1996-2020, The Board of Trustees of the University of Illinois,
// The Regents of the University of California, through Lawrence Berkeley National Laboratory
// (subject to receipt of any required approvals from the U.S. Dept. of Energy), Oak Ridge
// National Laboratory, managed by UT-Battelle, Alliance for Sustainable Energy, LLC, and other
// contributors. All rights reserved.
//
// NOTICE: This Software was developed under funding from the U.S. Department of Energy and the
// U.S. Government consequently retains certain rights. As such, the U.S. Government has been
// granted for itself and others acting on its behalf a paid-up, nonexclusive, irrevocable,
// worldwide license in the Software to reproduce, distribute copies to the public, prepare
// derivative works, and perform publicly and display publicly, and to permit others to do so.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of
//     conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National Laboratory,
//     the University of Illinois, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without specific prior
//     written permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in stand-alone form
//     without changes from the version obtained under this License, or (ii) Licensee makes a
//     reference solely to the software portion of its product, Licensee must refer to the
//     software as "EnergyPlus version X" software, where "X" is the version number Licensee
//     obtained under this License and may not use a different name for the software. Except as
//     specifically required in this Section (4), Licensee shall not use in a company name, a
//     product name, in advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+" or confusingly
//     similar designation, without the U.S. Department of Energy's prior written consent.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef DataGlobalConstants_hh_INCLUDED
#define DataGlobalConstants_hh_INCLUDED

// C++ Headers
#include <map>

// EnergyPlus Headers
#include <EnergyPlus/EnergyPlus.hh>

namespace EnergyPlus {

namespace DataGlobalConstants {

    enum class EndUse {
        Heating,
        Cooling,
        InteriorLights,
        ExteriorLights,
        InteriorEquipment,
        ExteriorEquipment,
        Fans,
        Pumps,
        HeatRejection,
        Humidification,
        HeatRecovery,
        WaterSystem,
        Refrigeration,
        Cogeneration
    };

    enum class ResourceType {
        None,
        Electricity,
        Natural_Gas,
        Gasoline,
        Diesel,
        Coal,
        FuelOil_1,
        FuelOil_2,
        Propane,
        Water,
        EnergyTransfer,
        Steam,
        DistrictCooling,
        DistrictHeating,
        ElectricityProduced,
        ElectricityPurchased,
        ElectricitySurplusSold,
        ElectricityNet,
        SolarWater,
        SolarAir,
        SO2,
        NOx,
        N2O,
        PM,
        PM2_5,
        PM10,
        CO,
        CO2,
        CH4,
        NH3,
        NMVOC,
        Hg,
        Pb,
        NuclearHigh,
        NuclearLow,
        WaterEnvironmentalFactors,
        CarbonEquivalent,
        Source,
        PlantLoopHeatingDemand,
        PlantLoopCoolingDemand,
        OnSiteWater,
        MainsWater,
        RainWater,
        WellWater,
        Condensate,
        OtherFuel1,
        OtherFuel2
    };

    enum class CallIndicator {
        BeginDay,
        DuringDay,
        EndDay,
        EndZoneSizingCalc,
        EndSysSizingCalc
    };

    // Parameters for KindOfSim
    enum class KindOfSim {
        Unassigned = 0,
        DesignDay = 1,
        RunPeriodDesign = 2,
        RunPeriodWeather = 3,
        HVACSizeDesignDay = 4,          // a regular design day run during HVAC Sizing Simulation
        HVACSizeRunPeriodDesign = 5,    // a weather period design day run during HVAC Sizing Simulation
        ReadAllWeatherData = 6          // a weather period for reading all weather data prior to the simulation
    };

    Real64 constexpr MaxEXPArg () { return 709.78; }                        // maximum exponent in EXP() function
    Real64 constexpr Pi () { return 3.14159265358979324; }                  // Pi 3.1415926535897932384626435
    Real64 constexpr PiOvr2 () { return Pi() / 2.0; }                       // Pi/2
    Real64 constexpr TwoPi () { return 2.0 * Pi(); }                        // 2*Pi 6.2831853071795864769252868
    Real64 constexpr GravityConstant () { return 9.807; }
    Real64 constexpr DegToRadians () { return Pi() / 180.0; }               // Conversion for Degrees to Radians
    Real64 constexpr RadToDeg () { return 180.0 / Pi(); }                   // Conversion for Radians to Degrees
    Real64 constexpr SecInHour () { return 3600.0; }                        // Conversion for hours to seconds
    Real64 constexpr HoursInDay () { return 24.0; }                         // Number of Hours in Day
    Real64 constexpr SecsInDay () { return SecInHour() * HoursInDay(); }    // Number of seconds in Day
    Real64 constexpr BigNumber () { return std::numeric_limits< Real64 >::max(); }  // Max Number real used for initializations
    Real64 constexpr rTinyValue () { return std::numeric_limits< Real64 >::epsilon(); }   // Tiny value to replace use of TINY(x)
    std::string::size_type constexpr MaxNameLength () { return 100; }       // Maximum Name Length in Characters -- should be the same as MaxAlphaArgLength in InputProcessor module
    Real64 constexpr KelvinConv () { return 273.15; }                       // Conversion factor for C to K and K to C
    Real64 constexpr InitConvTemp () { return 5.05; }                       // [deg C], standard init vol to mass flow conversion temp
    Real64 constexpr AutoCalculate () { return -99999.0; }                  // automatically calculate some fields.
    Real64 constexpr CWInitConvTemp () { return 5.05; }                     // [deg C], standard init chilled water vol to mass flow conversion temp
    Real64 constexpr HWInitConvTemp () { return 60.0; }                     // [deg C], standard init hot water vol to mass flow conversion temp
    Real64 constexpr SteamInitConvTemp () { return 100.0; }                 // [deg C], standard init steam vol to mass flow conversion temp
    Real64 constexpr StefanBoltzmann () { return 5.6697E-8; }               // Stefan-Boltzmann constant in W/(m2*K4)
    Real64 constexpr UniversalGasConst () { return 8314.462175; }           // Universal Gas Constant (J/mol*K)
    Real64 constexpr convertJtoGJ () { return 1.0E-9; }                     // Conversion factor for J to GJ
    int constexpr MaxSpeedLevels () { return 10; }                          // Maximum number of speed that supports
    int constexpr ScheduleAlwaysOn () { return -1; }                        // Value when passed to schedule routines gives back 1.0 (on)

    ResourceType AssignResourceTypeNum(std::string const &ResourceTypeChar);
    std::string GetResourceTypeChar(ResourceType ResourceTypeNum);

    extern std::vector<ResourceType> AllResourceTypes;
    extern std::map<EndUse, int> iEndUse;

} // namespace DataGlobalConstants

} // namespace EnergyPlus

#endif
