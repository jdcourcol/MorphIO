#pragma once

#include <memory> //std::unique_ptr

#include <morphio/properties.h>
#include <morphio/types.h>

namespace morphio
{
/** Read access a Morphology file.
 *
 * Following RAII, this class is ready to use after the creation and will ensure
 * release of resources upon destruction.
 */
class Morphology
{
public:
    /** Close morphology file. @version 1.0 */
    ~Morphology();

    Morphology(const builder::Morphology&);
    Morphology& operator=(const Morphology&);
    Morphology(Morphology&&);
    Morphology& operator=(Morphology&&);

    /** @name Read API */
    //@{
    /** Open the given source to a morphology file and parse it.
     *
     * The actual data loading happens in a background thread and is lazily
     * finalised in any get method. It is therefore faster to construct a set
     * of morphologies and then read their data over a serial construct-and-read
     * approach.
     *
     * @param source URI to load the morphology
     * @throw std::runtime_error if file is not a valid morphology file
     * @version 3.0
     */
    explicit Morphology(const URI& source);

    const Soma soma() const;
    const std::vector<Section> rootSections() const;
    const std::vector<Section> sections() const;

    /**
     * Return the Section with the given id.
     *
     * @throw runtime_error if the id is out of range or the given id refers to
     * a soma section.
     */
    const Section section(const uint32_t& id) const;

    const Points& points() const;
    const std::vector<float>& diameters() const;
    const std::vector<float>& perimeters() const;
    const std::vector<SectionType>& sectionTypes() const;
    const CellFamily& cellFamily() const;
    const MorphologyVersion& version() const;

private:
    std::shared_ptr<Property::Properties> _properties;

    template <typename Property>
    const std::vector<typename Property::Type>& get() const;
};
}
