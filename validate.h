/**
 * @file compare.h
 * @brief Validation helpers for FORMAT_Time, FORMAT_Date, and FORMAT_DateTime.
 *
 * This header declares utility functions to validate time- and date-related structures used in the core_types format module. The functions check whether the individual fields of FORMAT_Time, FORMAT_Date, and FORMAT_DateTime fall within acceptable ranges (for example hour 0–23, minute/second 0–59, valid day/month combinations, and a permitted year range).
 *
 * The functions return a core_types status code defined in core_types/return/status.h, allowing consistent error handling across modules.
 *
 * @author g.raf
 * @date 2026-02-14
 * @version 1.0 Release
 * @copyright
 * Copyright (c) 2026 g.raf
 * Released under the GPLv3 License. (see LICENSE in repository)
 *
 * @note This file is part of a larger utility library and subject to the license specified in the repository. For updates and the complete revision history, see the GitHub repository.
 *
 * @see https://github.com/0x007e/utils-time "Time Utilities GitHub Repository"
 */

#ifndef COMPARE_H_
#define COMPARE_H_

    #include "../../core_types/format/time.h"
    #include "../../core_types/return/status.h"

    RETURN_Data_Status validate_time(const FORMAT_Time *time);
    RETURN_Data_Status validate_date(const FORMAT_Date *date);
    RETURN_Data_Status validate_datetime(const FORMAT_DateTime *datetime);
    
#endif /* COMPARE_H_ */