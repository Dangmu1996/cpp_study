#pragma once


class Preferences;

class Logger
{
public:
    static void setPreferences(const Preferences &pref);
    static void logError();
};