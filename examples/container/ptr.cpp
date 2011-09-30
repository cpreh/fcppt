//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[container_ptr
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{

struct noncopyable
{
	FCPPT_NONCOPYABLE(
		noncopyable
	);
public:
	noncopyable()
	{
	}

	~noncopyable()
	{
	}
private:
	// some noncopyable data
};

}

int main()
{
	typedef boost::ptr_map<
		int,
		::noncopyable
	> int_noncopyable_map;

	int_noncopyable_map map;

	// insert a pair(42, unique_ptr<noncopyable>())
	fcppt::container::ptr::insert_unique_ptr_map(
		map,
		42,
		fcppt::make_unique_ptr<
			noncopyable
		>()
	);

	// print the address of the newly inserted element
	fcppt::io::cout()
		<< &map[42]
		<< FCPPT_TEXT('\n');
}
//]
