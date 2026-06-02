#ifndef directdownload_h
#define directdownload_h

#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"
#include <Update.h>

#define STRINGIFY(x) #x
#define EVALUATE_AND_STRINGIFY(x) STRINGIFY(x)

#ifndef FIRMWARE_RELEASE_NAME
#define FIRMWARE_RELEASE_NAME "esp32"
#endif

#define WORKER_URL "http://<worker_name>.<username>.workers.dev/?firmware="

/**
 * Cloudflare Worker: <worker_name>
 * http://<worker_name>.<username>.workers.dev/?firmware=<FIRMWARE_RELEASE_NAME>&tag=<RELEASE_TAG_NAME>
 * See file: ota_worker.js
 *
 * Returns 204 when tag matches latest release (already up to date).
 * Returns 200 + firmware binary when an update is available.
 */


enum UPDATE_STATUS
{
    UPDATE_STATUS_NONE,
    UPDATE_STATUS_SUCCESS,
    UPDATE_STATUS_FAIL_WIFI_CONNECTION,
    UPDATE_STATUS_FAIL_VERSION_REQUEST,
    UPDATE_STATUS_FAIL_FILE_REQUEST,
    UPDATE_STATUS_FAIL_GENERIC,
    UPDATE_STATUS_FAIL_ALREADY_UP_TO_DATE
};

extern void setupdateResult(byte value);

void downloadUpdate(String SSID, String PASS);

#endif