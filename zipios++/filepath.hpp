#pragma once
/*
  Zipios++ - a small C++ library that provides easy access to .zip files.
  Copyright (C) 2000-2015  Thomas Sondergaard

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

/** \file
 * \brief Header file that defines FilePath.
 *
 * FilePath is used to manage paths and filenames to files and directories.
 */

#include "zipios++/zipios-config.hpp"

#include <ctime>
#include <string>


namespace zipios
{


class FilePath
{
public:
                        FilePath(std::string const& path = "");

                        operator std::string () const;
    FilePath&           operator = (std::string const& path);
    FilePath            operator + (FilePath const& name) const;
    bool                operator == (char const *rhs) const;
    friend bool         operator == (char const *lhs, FilePath const& rhs);
    bool                operator == (std::string const& rhs) const;
    friend bool         operator == (std::string const& lhs, FilePath const& rhs);
    bool                operator == (FilePath const& rhs) const;
    // TBD: add all the other comparison operators for completeness
    std::string         filename() const;
    size_t              length() const;
    size_t              size() const;
    bool                exists() const;
    bool                isRegular() const;
    bool                isDirectory() const;
    bool                isCharSpecial() const;
    bool                isBlockSpecial() const;
    bool                isSocket() const;
    bool                isFifo() const;
    size_t              fileSize() const;
    std::time_t         lastModificationTime() const;

private:
    void                check() const;

    std::string         m_path;
    mutable os_stat_t   m_stat;
    mutable bool        m_checked = false;
    mutable bool        m_exists = false;
};


std::ostream& operator << (std::ostream& os, FilePath const& path);


} // namespace
// vim: ts=4 sw=4 et
