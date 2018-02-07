/* Copyright (c) 2013-2017, EPFL/Blue Brain Project
 *                          Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 *                          Juan Hernando <jhernando@fi.upm.es>
 *
 * This file is part of Brion <https://github.com/BlueBrain/Brion>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BRAIN_PLUGIN_MORPHOLOGYHDF5
#define BRAIN_PLUGIN_MORPHOLOGYHDF5

#include "../morphologyPlugin.h"

namespace minimorph
{
namespace plugin
{
class MorphologyHDF5 : public MorphologyPlugin
{
public:
    /** Create a new parser for an H5 morphology */
    explicit MorphologyHDF5(const MorphologyInitData& initData);

    ~MorphologyHDF5();

//TODO: compile
#if 0
    /** Check if this plugin can handle the given uri. */
    static bool handles(const MorphologyInitData& initData);
    static std::string getDescription();
#endif

private:
    void load() final;
};
}
}

#endif