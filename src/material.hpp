/** @file material.hpp
    @brief Material declarations.
    @author Luis Cabellos
    @date 2014-01-07
*/
//------------------------------------------------------------------------------
#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

//------------------------------------------------------------------------------
class Material{
public:
    void setDiffuse( const glm::vec3 & col ) noexcept;
    void setDiffuse( glm::vec3 && col ) noexcept;

    const glm::vec3 & getDiffuse() const noexcept;

private:
    glm::vec3 m_diffuse;
};

//------------------------------------------------------------------------------
inline
void Material::setDiffuse( const glm::vec3 & col ) noexcept {
    m_diffuse = col;
}

//------------------------------------------------------------------------------
inline
void Material::setDiffuse( glm::vec3 && col ) noexcept {
    m_diffuse = std::move(col);
}

//------------------------------------------------------------------------------
inline
const glm::vec3 & Material::getDiffuse() const noexcept {
    return m_diffuse;
}

//------------------------------------------------------------------------------
#endif//MATERIAL_HPP_

//------------------------------------------------------------------------------
