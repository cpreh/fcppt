//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_same.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
namespace strong_typedef_example
{
//! [strong_typedef_for_named_parameters_without_strong_typedef_without_typedef]
void f(int,bool,char);
//! [strong_typedef_for_named_parameters_without_strong_typedef_without_typedef]

//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef]
typedef
int
vertex_count;

typedef
bool
enable_culling;

typedef
char
draw_char;

void f(vertex_count,enable_culling,draw_char) {}
//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef]

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4305)

void g()
{
//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef_call_test]
f(100,true,'c');
f(true,100,'c');
f(true,'c',100);
f(100,'c',true);
f('c',true,100);
f('c',100,true);
//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef_call_test]
}

FCPPT_PP_POP_WARNING

//! [strong_typedef_for_named_parameters_with_strong_typedef]
namespace with_strong_typedef
{
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	vertex_count);

FCPPT_MAKE_STRONG_TYPEDEF(
	bool,
	enable_culling);

FCPPT_MAKE_STRONG_TYPEDEF(
	char,
	draw_char);

void f(vertex_count,enable_culling,draw_char) {}
}
//! [strong_typedef_for_named_parameters_with_strong_typedef]

namespace with_strong_typedef
{
void named_parameters_call_test()
{
//! [strong_typedef_for_named_parameters_with_strong_typedef_call_test]
f(
	vertex_count(100),
	enable_culling(false),
	draw_char('c'));
//! [strong_typedef_for_named_parameters_with_strong_typedef_call_test]
}
}

//! [strong_typedef_for_overloading_guards_definitions]
FCPPT_MAKE_STRONG_TYPEDEF(
        float,
        distance);

FCPPT_MAKE_STRONG_TYPEDEF(
        float,
        speed);

// While we're at it, add another type for the time!
FCPPT_MAKE_STRONG_TYPEDEF(
        float,
        time);
//! [strong_typedef_for_overloading_guards_definitions]

namespace jogger
{
distance elapsed_distance(0.0f);
speed current_speed(0.0f);
void update(time);
}

//! [strong_typedef_for_overloading_guards_example]
void
jogger::update(time tick_delta)
{
	elapsed_distance += distance(current_speed.get() * tick_delta.get());
}
//! [strong_typedef_for_overloading_guards_example]

//! [strong_typedef_is_same]
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	first);

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	second);

static_assert(
	!boost::is_same<first,second>::value,
	"Both types must be different"
);
//! [strong_typedef_is_same]

}
}

int main()
{
	strong_typedef_example::jogger::update(
		strong_typedef_example::time(
			1.0f));

	strong_typedef_example::g();

	strong_typedef_example::f(1,true,'c');

	strong_typedef_example::with_strong_typedef::named_parameters_call_test();
}
