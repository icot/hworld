/** @file c_null.hpp
    @brief Null Component.
    @author Luis Cabellos
    @date 2013-10-13
*/
//------------------------------------------------------------------------------
#ifndef C_NULL_HPP_
#define C_NULL_HPP_

//------------------------------------------------------------------------------
#include "component.hpp"

//------------------------------------------------------------------------------
class CNull : public Component {
public:
    constexpr static ComponentType type = ComponentType::CT_NULL;

    CNull( Entity & e );

    ComponentType getType() const override;

    void test() const;

private:
};

//------------------------------------------------------------------------------
inline
ComponentType CNull::getType() const{
    return type;
}

//------------------------------------------------------------------------------
#endif//C_NULL_HPP_

//------------------------------------------------------------------------------
