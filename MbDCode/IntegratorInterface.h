#pragma once

#include "Integrator.h"
//#include "BasicQuasiIntegrator.h"

namespace MbD {
    class BasicQuasiIntegrator;

    class IntegratorInterface : public Integrator
    {
        //tout hout hmin hmax tstart tend integrator 
    public:

        void initializeGlobally() override;
        virtual void preRun() = 0;
        virtual void checkForDiscontinuity() = 0;
        
        void setSystem(Solver* sys) override;
        void logString(std::string& str) override;
        void run() override;
        int orderMax();
        virtual void incrementTime(double tnew);

        void postFirstStep() override;
        virtual double suggestSmallerOrAcceptFirstStepSize(double hnew) = 0;
        virtual double suggestSmallerOrAcceptStepSize(double hnew) = 0;
        virtual void checkForOutputThrough(double t) = 0;
        virtual void interpolateAt(double t);

        SystemSolver* system;
        double tout = 0, hout = 0, hmin = 0, hmax = 0, tstart = 0, tend = 0;
        std::shared_ptr<BasicQuasiIntegrator> integrator;
    };
}

