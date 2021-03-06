/*---------------------------------------------------------------------\
|                                                                      |  
|                      __   __    ____ _____ ____                      |  
|                      \ \ / /_ _/ ___|_   _|___ \                     |  
|                       \ V / _` \___ \ | |   __) |                    |  
|                        | | (_| |___) || |  / __/                     |  
|                        |_|\__,_|____/ |_| |_____|                    |  
|                                                                      |  
|                               core system                            | 
|                                                        (C) SuSE GmbH |  
\----------------------------------------------------------------------/ 

   File:       YCPString.h

   Author:     Mathias Kettner <kettner@suse.de>
   Maintainer: Thomas Roelz <tom@suse.de>

/-*/
// -*- c++ -*-

#ifndef YCPString_h
#define YCPString_h


#include "YCPValue.h"
#include <y2util/Ustring.h>

   
/**
 * @short YCPValueRep representing a character string of
 * arbitrary length.
 * Whatever internal representation is choosen: It should
 * be possible to switch to 16 bit Unicode strings, when
 * neccessary.
 * 
 * YCP Syntax: Doublequoted ASCII string.
 * <pre>"This is a string", "", "08712345"</pre>
 */
class YCPStringRep : public YCPValueRep
{

    string v;
    bool is_ascii;

protected:

    friend class YCPString;

    /**
     * Creates a new YCPStringRep from a C++ string.
     * @param s A string that is taken literally as value of the newly create
     * YCPStringRep object. Not expansion of backslashes is done, s is not
     * considered to be enclosed with quotes. If there are quotes, they are
     * considered to be part of the string. The string must be UTF-8 encoded.
     */
    YCPStringRep(const string& s);

    /**
     * Creates a new YCPStringRep from a C++ wstring.
     * @param s A wstring that is taken literally as value of the newly create
     * YCPStringRep object. Not expansion of backslashes is done, s is not
     * considered to be enclosed with quotes. If there are quotes, they are
     * considered to be part of the string.
     */
    YCPStringRep(const wstring& s);

public:

    /**
     * Returns true iff this string is empty.
     */
    bool isEmpty() const;

    /**
     * Returns true iff the string only contains ASCII characters.
     */
    bool isAscii() const { return is_ascii; }

    /**
     * Returns the value of this object in form of a C++ string value.
     */
    const string& value() const;

    /**
     * Returns the value of this object in form of a C++ wstring value.
     */
    wstring wvalue() const;

    /**
     * Compares two YCPStrings for equality, greaterness or smallerness.
     * @param v value to compare against
     * @param rl respect locale
     * @return YO_LESS,    if this is smaller than v,
     *         YO_EQUAL,   if this is equal to v,
     *         YO_GREATER, if this is greater to v
     */
    YCPOrder compare(const YCPString &v, bool rl = false) const;

    /**
     * Returns the value in form of a C const char * string.
     */
    const char *value_cstr() const;

    /**
     * Returns a string representation of the value of this
     * object. It contains enclosing quotes. Newlines and
     * quotes contained in the string itself are quoted with
     * backslashes.
     */
    string toString() const;

    /**
     * Output value as bytecode to stream
     */
    std::ostream & toStream (std::ostream & str) const;
    std::ostream & toXml (std::ostream & str, int indent ) const;

    /**
     * Returns YT_STRING. See @ref YCPValueRep#valuetype.
     */
    YCPValueType valuetype() const;
};


#define CONST_ELEMENT (static_cast<const YCPStringRep*>(element))

/**
 * @short Wrapper for YCPStringRep
 * This class realizes an automatic memory management
 * via @ref YCPElement. Access the functionality of YCPStringRep
 * with the arrow operator. See @ref YCPStringRep.
 */
class YCPString : public YCPValue
{
    DEF_COMMON(String, Value);
public:
    YCPString(const string& s) : YCPValue(new YCPStringRep(s)) {}
    YCPString(const wstring& s) : YCPValue(new YCPStringRep(s)) {}
    YCPString(bytecodeistream & str);

    bool isEmpty() const { return CONST_ELEMENT->isEmpty(); }
};

#undef CONST_ELEMENT

#endif   // YCPString_h
