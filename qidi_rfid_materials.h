#pragma once

// QIDI Box filament material codes.
// Values are the DECIMAL codes from the QIDI RFID wiki
// (https://wiki.qidi3d.com/en/QIDIBOX/RFID). The code is written
// directly into tag byte 0, so e.g. 40 (decimal) is stored as 0x28.
typedef enum {
    MaterialPLA = 1,
    MaterialPLA_Matte = 2,
    MaterialPLA_Metal = 3,
    MaterialPLA_Silk = 4,
    MaterialPLA_CF = 5,
    MaterialPLA_Wood = 6,
    MaterialPLA_Basic = 7,
    MaterialPLA_Matte_Basic = 8,
    MaterialABS = 11,
    MaterialABS_GF = 12,
    MaterialABS_Metal = 13,
    MaterialABS_Odorless = 14,
    MaterialASA = 18,
    MaterialASA_AERO = 19,
    MaterialUltraPA = 24,
    MaterialPA_CF = 25,
    MaterialUltraPA_CF25 = 26,
    MaterialPA12_CF = 27,
    MaterialPAHT_CF = 30,
    MaterialPAHT_GF = 31,
    MaterialSupport_PAHT = 32,
    MaterialSupport_PET_PA = 33,
    MaterialPC_ABS_FR = 34,
    MaterialPET_CF = 37,
    MaterialPET_GF = 38,
    MaterialPETG_Basic = 39,
    MaterialPETG_Tough = 40,
    MaterialPETG_Rapido = 41,
    MaterialPETG_CF = 42,
    MaterialPETG_GF = 43,
    MaterialPPS_CF = 44,
    MaterialPETG_Translucent = 45,
    MaterialPVA = 47,
    MaterialTPU_Aero = 49,
    MaterialTPU = 50,
} QidiMaterial;

typedef struct {
    QidiMaterial code;
    const char* name;
} QidiMaterialInfo;

static const QidiMaterialInfo qidi_materials[] = {
    {MaterialPLA, "PLA"},
    {MaterialPLA_Matte, "PLA Matte"},
    {MaterialPLA_Metal, "PLA Metal"},
    {MaterialPLA_Silk, "PLA Silk"},
    {MaterialPLA_CF, "PLA-CF"},
    {MaterialPLA_Wood, "PLA-Wood"},
    {MaterialPLA_Basic, "PLA Basic"},
    {MaterialPLA_Matte_Basic, "PLA Matte Basic"},
    {MaterialABS, "ABS"},
    {MaterialABS_GF, "ABS-GF"},
    {MaterialABS_Metal, "ABS-Metal"},
    {MaterialABS_Odorless, "ABS-Odorless"},
    {MaterialASA, "ASA"},
    {MaterialASA_AERO, "ASA-AERO"},
    {MaterialUltraPA, "UltraPA"},
    {MaterialPA_CF, "PA-CF"},
    {MaterialUltraPA_CF25, "UltraPA-CF25"},
    {MaterialPA12_CF, "PA12-CF"},
    {MaterialPAHT_CF, "PAHT-CF"},
    {MaterialPAHT_GF, "PAHT-GF"},
    {MaterialSupport_PAHT, "Support For PAHT"},
    {MaterialSupport_PET_PA, "Support For PET/PA"},
    {MaterialPC_ABS_FR, "PC/ABS-FR"},
    {MaterialPET_CF, "PET-CF"},
    {MaterialPET_GF, "PET-GF"},
    {MaterialPETG_Basic, "PETG Basic"},
    {MaterialPETG_Tough, "PETG Tough"},
    {MaterialPETG_Rapido, "PETG Rapido"},
    {MaterialPETG_CF, "PETG-CF"},
    {MaterialPETG_GF, "PETG-GF"},
    {MaterialPPS_CF, "PPS-CF"},
    {MaterialPETG_Translucent, "PETG Translucent"},
    {MaterialPVA, "PVA"},
    {MaterialTPU_Aero, "TPU-Aero"},
    {MaterialTPU, "TPU"},
};

#define QIDI_MATERIAL_COUNT (sizeof(qidi_materials) / sizeof(QidiMaterialInfo))
