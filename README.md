[![Version: 1.0 Release](https://img.shields.io/badge/Version-1.0%20Release-green.svg)](https://github.com/0x007e/utils-time) ![Build](https://github.com/0x007e/utils-time/actions/workflows/release.yml/badge.svg) [![License GPLv3](https://img.shields.io/badge/License-GPLv3-lightgrey)](https://www.gnu.org/licenses/gpl-3.0.html)

# `Time Utils`

[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/0x007E/utils-time)

This utility can be used to validate a `time`/`date`/`datetime`.

## File Structure

![File Structure](https://0x007e.github.io/utils-time/compare_8c__incl.png)

```
utils/
└── time/
    ├── validate.c
    └── validate.h

core_types/
├── format/
|   └── time.h
└── return/
    └── status.h
```

> The library is completely patform independent and can be usesd across a wide range of c-compilers.

## Downloads

The library can be downloaded (`zip` or `tar`), cloned or used as submodule in a project.

| Type      | File               | Description              |
|:---------:|:------------------:|:-------------------------|
| Library   | [zip](https://github.com/0x007E/utils-time/releases/latest/download/library.zip) / [tar](https://github.com/0x007E/utils-time/releases/latest/download/library.tar.gz) | Time utility library that implements time/date/datetime validation |

### Using with `git clone`

```sh
mkdir -p ./core_types/
git clone https://github.com/0x007E/core_types-format.git ./core_types
mv ./core_types/core_types-format ./core_types/format
git clone https://github.com/0x007E/core_types-return.git ./core_types
mv ./core_types/core_types-return ./core_types/return

mkdir -p ./utils/
git clone https://github.com/0x007E/utils-time.git    ./utils
mv ./utils/utils-time ./utils/time
```

### Using as `git submodule`

```sh
git submodule add https://github.com/0x007E/core_types-format.git ./core_types/format
git submodule add https://github.com/0x007E/core_types-return.git ./core_types/return
git submodule add https://github.com/0x007E/utils-time.git    ./utils/time
```

## Programming

```c
#include "../lib/utils/time/validate.h"

int main(void)
{
    FORMAT_Time time;
    time.hour = 10;
    time.minute = 20;
    time.second = 30;

    FORMAT_Date date;
    date.day = 10;
    date.month = 10;
    date.year = 26;

    FORMAT_DateTime datetime;
    datetime.time.hour = 10;
    datetime.time.minute = 20;
    datetime.time.second = 30;
    datetime.date.day = 10;
    datetime.date.month = 10;
    datetime.date.year = 26;


    if(validate_time(time) != RETURN_Valid)
    {
        // Error Handling
    }

    if(validate_date(date) != RETURN_Valid)
    {
        // Error Handling
    }

    if(validate_datetime(datetime) != RETURN_Valid)
    {
        // Error Handling
    }
}
```

---

R. GAECHTER