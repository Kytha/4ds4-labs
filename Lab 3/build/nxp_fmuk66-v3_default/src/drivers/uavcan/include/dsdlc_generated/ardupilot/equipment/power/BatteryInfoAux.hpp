/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/ds/Documents/23/PX4-Autopilot/src/drivers/uavcan/libuavcan/dsdl/ardupilot/equipment/power/20004.BatteryInfoAux.uavcan
 */

#ifndef ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_HPP_INCLUDED
#define ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

#include <uavcan/Timestamp.hpp>

/******************************* Source text **********************************
#
# Auxilary Single battery info.
#
# This message is to be used in conjunction with uavcan/equipment/power/1092.BatteryInfo.uavcan

# Please ensure that this message is sent before the BatteryInfo which doesn't
# include the timestamp. The following fields should contain the timestamp of the last current measurement.
uavcan.Timestamp timestamp

# Battery individual cell voltages
# length of following field also used as cell count
float16[<=255] voltage_cell          # [Volt]

# Number of Charge/Discharge Cycles
# A charge cycle is defined as a complete discharge and charge.
# IE when the system uses all of the battery's available energy capacity.
# Please note that this value doesn't mean that the cycle count should be incremented at every charge.
# For example, if half of a battery's charge is used in one run,
# and then recharged fully that is half of a cycle. If the same thing occurs again
# then the charge cycle count would be incremented once, not twice.
uint16 cycle_count

# Number of times the battery was discharged over the rated capacity
uint16 over_discharge_count

# Max instantaneous current draw since last message
float16 max_current                 # [Ampere]

# Nominal voltage of the battery pack
# the nominal Voltage can be used for conversion between Wh and Ah
# if the value of this field is 0, the conversion should be omitted.
float16 nominal_voltage             # [Volt]

bool is_powering_off                # Power off event imminent indication, false if unknown

uint8 battery_id                    # Identifies the battery within this vehicle, e.g. 0 - primary battery
******************************************************************************/

/********************* DSDL signature source definition ***********************
ardupilot.equipment.power.BatteryInfoAux
uavcan.Timestamp timestamp
saturated float16[<=255] voltage_cell
saturated uint16 cycle_count
saturated uint16 over_discharge_count
saturated float16 max_current
saturated float16 nominal_voltage
saturated bool is_powering_off
saturated uint8 battery_id
******************************************************************************/

#undef timestamp
#undef voltage_cell
#undef cycle_count
#undef over_discharge_count
#undef max_current
#undef nominal_voltage
#undef is_powering_off
#undef battery_id

namespace ardupilot
{
namespace equipment
{
namespace power
{

template <int _tmpl>
struct UAVCAN_EXPORT BatteryInfoAux_
{
    typedef const BatteryInfoAux_<_tmpl>& ParameterType;
    typedef BatteryInfoAux_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::Timestamp timestamp;
        typedef ::uavcan::Array< ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 255 > voltage_cell;
        typedef ::uavcan::IntegerSpec< 16, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > cycle_count;
        typedef ::uavcan::IntegerSpec< 16, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > over_discharge_count;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > max_current;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > nominal_voltage;
        typedef ::uavcan::IntegerSpec< 1, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > is_powering_off;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > battery_id;
    };

    enum
    {
        MinBitLen
            = FieldTypes::timestamp::MinBitLen
            + FieldTypes::voltage_cell::MinBitLen
            + FieldTypes::cycle_count::MinBitLen
            + FieldTypes::over_discharge_count::MinBitLen
            + FieldTypes::max_current::MinBitLen
            + FieldTypes::nominal_voltage::MinBitLen
            + FieldTypes::is_powering_off::MinBitLen
            + FieldTypes::battery_id::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::timestamp::MaxBitLen
            + FieldTypes::voltage_cell::MaxBitLen
            + FieldTypes::cycle_count::MaxBitLen
            + FieldTypes::over_discharge_count::MaxBitLen
            + FieldTypes::max_current::MaxBitLen
            + FieldTypes::nominal_voltage::MaxBitLen
            + FieldTypes::is_powering_off::MaxBitLen
            + FieldTypes::battery_id::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::timestamp >::Type timestamp;
    typename ::uavcan::StorageType< typename FieldTypes::voltage_cell >::Type voltage_cell;
    typename ::uavcan::StorageType< typename FieldTypes::cycle_count >::Type cycle_count;
    typename ::uavcan::StorageType< typename FieldTypes::over_discharge_count >::Type over_discharge_count;
    typename ::uavcan::StorageType< typename FieldTypes::max_current >::Type max_current;
    typename ::uavcan::StorageType< typename FieldTypes::nominal_voltage >::Type nominal_voltage;
    typename ::uavcan::StorageType< typename FieldTypes::is_powering_off >::Type is_powering_off;
    typename ::uavcan::StorageType< typename FieldTypes::battery_id >::Type battery_id;

    BatteryInfoAux_()
        : timestamp()
        , voltage_cell()
        , cycle_count()
        , over_discharge_count()
        , max_current()
        , nominal_voltage()
        , is_powering_off()
        , battery_id()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<4217 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 20004 };

    static const char* getDataTypeFullName()
    {
        return "ardupilot.equipment.power.BatteryInfoAux";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool BatteryInfoAux_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        timestamp == rhs.timestamp &&
        voltage_cell == rhs.voltage_cell &&
        cycle_count == rhs.cycle_count &&
        over_discharge_count == rhs.over_discharge_count &&
        max_current == rhs.max_current &&
        nominal_voltage == rhs.nominal_voltage &&
        is_powering_off == rhs.is_powering_off &&
        battery_id == rhs.battery_id;
}

template <int _tmpl>
bool BatteryInfoAux_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(timestamp, rhs.timestamp) &&
        ::uavcan::areClose(voltage_cell, rhs.voltage_cell) &&
        ::uavcan::areClose(cycle_count, rhs.cycle_count) &&
        ::uavcan::areClose(over_discharge_count, rhs.over_discharge_count) &&
        ::uavcan::areClose(max_current, rhs.max_current) &&
        ::uavcan::areClose(nominal_voltage, rhs.nominal_voltage) &&
        ::uavcan::areClose(is_powering_off, rhs.is_powering_off) &&
        ::uavcan::areClose(battery_id, rhs.battery_id);
}

template <int _tmpl>
int BatteryInfoAux_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timestamp::encode(self.timestamp, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::voltage_cell::encode(self.voltage_cell, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::cycle_count::encode(self.cycle_count, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::over_discharge_count::encode(self.over_discharge_count, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::max_current::encode(self.max_current, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::nominal_voltage::encode(self.nominal_voltage, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::is_powering_off::encode(self.is_powering_off, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::battery_id::encode(self.battery_id, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int BatteryInfoAux_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timestamp::decode(self.timestamp, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::voltage_cell::decode(self.voltage_cell, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::cycle_count::decode(self.cycle_count, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::over_discharge_count::decode(self.over_discharge_count, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::max_current::decode(self.max_current, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::nominal_voltage::decode(self.nominal_voltage, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::is_powering_off::decode(self.is_powering_off, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::battery_id::decode(self.battery_id, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature BatteryInfoAux_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0xCD885C5A15770236ULL);

    FieldTypes::timestamp::extendDataTypeSignature(signature);
    FieldTypes::voltage_cell::extendDataTypeSignature(signature);
    FieldTypes::cycle_count::extendDataTypeSignature(signature);
    FieldTypes::over_discharge_count::extendDataTypeSignature(signature);
    FieldTypes::max_current::extendDataTypeSignature(signature);
    FieldTypes::nominal_voltage::extendDataTypeSignature(signature);
    FieldTypes::is_powering_off::extendDataTypeSignature(signature);
    FieldTypes::battery_id::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef BatteryInfoAux_<0> BatteryInfoAux;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::ardupilot::equipment::power::BatteryInfoAux > _uavcan_gdtr_registrator_BatteryInfoAux;

}

} // Namespace power
} // Namespace equipment
} // Namespace ardupilot

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::ardupilot::equipment::power::BatteryInfoAux::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux >::stream(Stream& s, ::ardupilot::equipment::power::BatteryInfoAux::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "timestamp: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::timestamp >::stream(s, obj.timestamp, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "voltage_cell: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::voltage_cell >::stream(s, obj.voltage_cell, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "cycle_count: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::cycle_count >::stream(s, obj.cycle_count, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "over_discharge_count: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::over_discharge_count >::stream(s, obj.over_discharge_count, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "max_current: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::max_current >::stream(s, obj.max_current, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "nominal_voltage: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::nominal_voltage >::stream(s, obj.nominal_voltage, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "is_powering_off: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::is_powering_off >::stream(s, obj.is_powering_off, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "battery_id: ";
    YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux::FieldTypes::battery_id >::stream(s, obj.battery_id, level + 1);
}

}

namespace ardupilot
{
namespace equipment
{
namespace power
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::ardupilot::equipment::power::BatteryInfoAux::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::ardupilot::equipment::power::BatteryInfoAux >::stream(s, obj, 0);
    return s;
}

} // Namespace power
} // Namespace equipment
} // Namespace ardupilot

#endif // ARDUPILOT_EQUIPMENT_POWER_BATTERYINFOAUX_HPP_INCLUDED