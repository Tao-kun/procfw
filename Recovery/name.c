#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pspsdk.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <psputility.h>

#include "systemctrl.h"
#include "systemctrl_se.h"
#include "vshctrl.h"
#include "utils.h"
#include "vpl.h"
#include "main.h"
#include "pspusbdevice.h"

static const int cpu_list[]={0, 20, 75, 100, 133, 222, 266, 300, 333};
static const int bus_list[]={0, 10, 37, 50, 66, 111, 133, 150, 166};

const char *get_bool_name(int boolean)
{
	if(boolean) {
		return g_messages[ENABLED];
	}

	return g_messages[DISABLED];
}

const char* get_fake_region_name(int fakeregion)
{
	switch(fakeregion) {
		case FAKE_REGION_DISABLED:
			return g_messages[DISABLED];
		case FAKE_REGION_JAPAN:
			return g_messages[JAPAN];
		case FAKE_REGION_AMERICA:
			return g_messages[AMERICA];
		case FAKE_REGION_EUROPE:
			return g_messages[EUROPE];
		case FAKE_REGION_KOREA:
			return g_messages[KOREA];
		case FAKE_REGION_UNK:
			return g_messages[UNITED_KINGDOM];
		case FAKE_REGION_UNK2:
			return g_messages[MEXIQUE];
		case FAKE_REGION_AUSTRALIA:
			return g_messages[AUSTRALIA];
		case FAKE_REGION_HONGKONG:
			return g_messages[HONGKONG];
		case FAKE_REGION_TAIWAN:
			return g_messages[TAIWAN];
		case FAKE_REGION_RUSSIA:
			return g_messages[RUSSIA];
		case FAKE_REGION_CHINA:
			return g_messages[CHINA];
		case FAKE_REGION_DEBUG_TYPE_I:
			return g_messages[DEBUG_TYPE_I];
		case FAKE_REGION_DEBUG_TYPE_II:
			return g_messages[DEBUG_TYPE_II];
	}

	return "FIXME";
}

const char *get_iso_name(int iso_mode)
{
	switch(iso_mode) {
		case MODE_UMD:
			return "Normal";
		case MODE_MARCH33:
			return "M33 driver";
		case MODE_NP9660:
			return "Sony NP9660";
	}

	return "FIXME";
}

int get_cpu_number(int cpu)
{
	int i;

	for(i=0; i<NELEMS(cpu_list); i++) {
		if(cpu==cpu_list[i])
			return i;
	}

	return 0;
}

int get_bus_number(int cpu)
{
	int i;

	for(i=0; i<NELEMS(bus_list); i++) {
		if(cpu==bus_list[i])
			return i;
	}

	return 0;
}

int get_cpu_freq(int number)
{
	if(number >= 0 && number < NELEMS(cpu_list)) {
		return cpu_list[number];
	}

	return 0;
}

int get_bus_freq(int number)
{
	if(number >= 0 && number < NELEMS(bus_list)) {
		return bus_list[number];
	}

	return 0;
}

const char *get_plugin_name(int type)
{
	switch(type) {
		case TYPE_VSH:
			return "VSH";
		case TYPE_GAME:
			return "GAME";
		case TYPE_POPS:
			return "POPS";
	}

	return "FIXME";
}

const char* get_usbdevice_name(int usbdevice)
{
	if(usbdevice == 0) {
		return g_messages[MEMORY_STICK];
	}

	switch(usbdevice-1) {
		case PSP_USBDEVICE_FLASH0:
			return g_messages[FLASH0];
		case PSP_USBDEVICE_FLASH1:
			return g_messages[FLASH1];
		case PSP_USBDEVICE_FLASH2:
			return g_messages[FLASH2];
		case PSP_USBDEVICE_FLASH3:
			return g_messages[FLASH3];
		case PSP_USBDEVICE_UMD9660:
			return g_messages[UMD9660];
	}

	return "FIXME";
}
