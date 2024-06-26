#pragma once

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#include <cstdlib>
#include <cstdio>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);