/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <sofa/component/linearsolver/direct/EigenSolverFactory.h>
#include <Eigen/MetisSupport>
#include <sofa/component/linearsolver/direct/init.h>
#include <sofa/core/ObjectFactory.h>
namespace sofa::component::linearsolver::direct
{
    
extern "C" {
    SOFA_EXPORT_DYNAMIC_LIBRARY void initExternalModule();
    SOFA_EXPORT_DYNAMIC_LIBRARY const char* getModuleName();
    SOFA_EXPORT_DYNAMIC_LIBRARY const char* getModuleVersion();
    SOFA_EXPORT_DYNAMIC_LIBRARY const char* getModuleComponentList();
}

void initExternalModule()
{
    init();
}

const char* getModuleName()
{
    return MODULE_NAME;
}

const char* getModuleVersion()
{
    return MODULE_VERSION;
}

template<class EigenSolverFactory, class Scalar>
void registerOrderingMethods()
{
    EigenSolverFactory::template registerSolver<Eigen::AMDOrdering<int>, Scalar >("AMD");
    EigenSolverFactory::template registerSolver<Eigen::COLAMDOrdering<int>, Scalar >("COLAMD");
    EigenSolverFactory::template registerSolver<Eigen::NaturalOrdering<int>, Scalar >("Natural");
    EigenSolverFactory::template registerSolver<Eigen::MetisOrdering<int>, Scalar >("Metis");
}

template<class Scalar>
void registerOrderingMethods()
{
    registerOrderingMethods<MainSimplicialLDLTFactory, Scalar>();
    registerOrderingMethods<MainSimplicialLLTFactory, Scalar>();
    registerOrderingMethods<MainLUFactory, Scalar>();
    registerOrderingMethods<MainQRFactory, Scalar>();
}

void init()
{
    static bool first = true;
    if (first)
    {
        registerOrderingMethods<float>();
        registerOrderingMethods<double>();

        first = false;
    }
}

const char* getModuleComponentList()
{
    /// string containing the names of the classes provided by the plugin
    static std::string classes = core::ObjectFactory::getInstance()->listClassesFromTarget(MODULE_NAME);
    return classes.c_str();
}
} // namespace sofa::component::linearsolver::direct
