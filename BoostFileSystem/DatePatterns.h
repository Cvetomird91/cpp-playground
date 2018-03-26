#ifndef DATEPATTERNS_H
#define DATEPATTERNS_H
#include <boost/regex.hpp>

struct date_patterns {
    static boost::regex date_month;
    static boost::regex year_month_day;
    static boost::regex day_month_year_dotdelimiter;
    static boost::regex day_month_short_year_dotdelimiter;
    static boost::regex day_month_year;
};

boost::regex date_patterns::date_month("asd");
boost::regex date_patterns::year_month_day("asd");
boost::regex date_patterns::day_month_year_dotdelimiter("asd");
boost::regex date_patterns::day_month_short_year_dotdelimiter("asd");
boost::regex date_patterns::day_month_year("asd");

#endif // DATEPATTERNS_H
/*
    0505
    20170505
    02.05.2017
    14.05.17
    02052017
*/
