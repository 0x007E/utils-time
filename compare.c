/**
 * @file compare.c
 * @brief Implements validation helpers for time and date format structures.
 *
 * @details
 * This source file provides the implementation of the validation functions declared in compare.h. It performs range and consistency checks on FORMAT_Time, FORMAT_Date, and FORMAT_DateTime structures, ensuring that their fields represent valid time and calendar values (for example, hour 0–23, minute/second 0–59, valid day-month combinations, and an allowed year range). The functions return shared status codes so that callers can uniformly handle valid and invalid input across the project.
 *
 * @author g.raf
 * @date 2026-02-14
 * @version 1.0 Release
 * @copyright
 * Copyright (c) 2026 g.raf
 * Released under the GPLv3 License. (see LICENSE in repository)
 *
 * @note This file is part of the time utilities module and subject to the license specified in the repository. For updates and the complete revision history, see the GitHub repository.
 *
 * @see https://github.com/0x007e/utils-time "Time Utilities GitHub Repository"
 */

#include "compare.h"

/**
 * @brief Validates a FORMAT_Time instance for proper hour, minute, and second ranges.
 *
 * @param time Pointer to a ::FORMAT_Time structure whose fields will be checked:
 * - hour   (expected range: 0–23)
 * - minute (expected range: 0–59)
 * - second (expected range: 0–59)
 *
 * @return Returns one of the following status codes:
 * - `RETURN_Valid` if all time fields are within their expected ranges.
 * - `RETURN_Invalid` if any of the fields contain an out-of-range value.
 *
 * @details
 * This function performs a simple range validation on the provided @p time structure. If hour, minute, or second exceed their respective limits, the function reports an invalid status; otherwise, it reports a valid time.
 */
RETURN_Data_Status time_validate_time(const FORMAT_Time *time)
{
    if((time->hour > 23) || (time->minute > 59) || (time->second > 59))
    {
        return RETURN_Invalid;
    }
    return RETURN_Valid;
}

/**
 * @brief Validates a FORMAT_Date instance for basic day, month, and year ranges.
 *
 * @param date Pointer to a ::FORMAT_Date structure whose fields will be checked:
 * - day   (expected range: 1–31, only an upper-bound check is performed here)
 * - month (expected range: 1–12, only an upper-bound check is performed here)
 * - year  (expected range: 0–99, interpreted as an application-defined offset)
 *
 * @return Returns one of the following status codes:
 * - `RETURN_Valid` if all date fields are within their configured ranges.
 * - `RETURN_Invalid` if any of the fields contain an out-of-range value.
 *
 * @details
 * This function performs a simple, range-based validation on the provided @p date structure. It checks only the maximum values for day, month, and year, and does not account for month-specific day counts or leap years. For stricter calendar validation, additional checks must be applied by the caller or a higher-level routine.
 */
RETURN_Data_Status time_validate_date(const FORMAT_Date *date)
{
    if((date->day > 31) || (date->month > 12) || (date->year > 99))
    {
        return RETURN_Invalid;
    }
    return RETURN_Valid;
}

/**
 * @brief Validates a FORMAT_DateTime instance by checking its date and time components.
 *
 * @param datetime Pointer to a ::FORMAT_DateTime structure whose @p date and @p time substructures will be validated using time_validate_date() and time_validate_time().
 *
 * @return Returns a combined status code:
 * - `RETURN_Valid` if both the date and time components are valid.
 * - `RETURN_Invalid` if either the date or the time (or both) are invalid.
 *
 * @details
 * This function delegates validation to time_validate_time() for the time portion and time_validate_date() for the date portion of @p datetime. The individual results are bitwise OR-combined into a single RETURN_Data_Status value, allowing callers to treat any invalid subcomponent as an overall invalid date-time.
 */
RETURN_Data_Status time_validate_datetime(const FORMAT_DateTime *datetime)
{
    RETURN_Data_Status status = RETURN_Valid;

    status |= time_validate_time(&datetime->time);
    status |= time_validate_date(&datetime->date);

    return status;
}