#pragma once

#include <morphio/section_base.h>
#include <morphio/properties.h>
#include <morphio/mitochondria.h>
#include <morphio/types.h>

namespace morphio
{
class MitoSection : public SectionBase<MitoSection>
{
    typedef Property::MitoSection SectionId;
    typedef Property::MitoDiameter PointAttribute;
public:
    /**
       Depth first search iterator
    **/
    mito_depth_iterator depth_begin() const;
    mito_depth_iterator depth_end() const;

    /**
       Breadth first search iterator
    **/
    mito_breadth_iterator breadth_begin() const;
    mito_breadth_iterator breadth_end() const;

    /**
       Upstream first search iterator
    **/
    mito_upstream_iterator upstream_begin() const;
    mito_upstream_iterator upstream_end() const;


    /**
     * Returns list of neuronal section IDs associated to each point
     **/
    const range<const uint32_t> neuriteSectionIds() const;

    /**
     * Returns list of section's point diameters
     **/
    const range<const float> diameters() const;

    /**
     * Returns list of relative distances between the start
     * of the neuronal section and each point of the mitochondrial section\n
     * Note: - a relative distance of 0 means the mitochondrial point is at the
     *         beginning of the neuronal section
     *       - a relative distance of 1 means the mitochondrial point is at the
     *         end of the neuronal section
     **/
    const range<const float> relativePathLengths() const;

    /** Return the morphological type of this section (dendrite, axon, ...). */
    const SectionType type() const;



protected:
    MitoSection(uint32_t id, std::shared_ptr<Property::Properties> morphology) : SectionBase(id, morphology) {}
    friend const MitoSection Mitochondria::section(const uint32_t&) const;
    friend class SectionBase<MitoSection>;
    friend class mut::MitoSection;


};
} // namespace morphio
