//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/raw_container_source.hpp>
#include <fcppt/container/raw_vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

BOOST_AUTO_TEST_CASE(main_test)
{
	typedef
	fcppt::container::raw_vector<char>
	raw_container;

	typedef
	fcppt::io::raw_container_source<raw_container>
	raw_source;

	typedef
	boost::iostreams::stream<raw_source>
	stream_type;

	typedef
	std::vector<char>
	other_container;

	other_container other;
	other.push_back('a');
	other.push_back('b');
	other.push_back('c');

	stream_type stream(
		other.begin(),
		other.end());

	char bytes[3];
	stream.read(
		bytes,
		std::ios_base::binary);

	BOOST_CHECK(
		bytes[0] == 'a');
	BOOST_CHECK(
		bytes[1] == 'b');
	BOOST_CHECK(
		bytes[2] == 'c');
	BOOST_CHECK(
		stream.eof());

	stream.clear();

	stream.seekg(
		0,
		std::ios_base::beg);

	BOOST_CHECK(
		!stream.eof());

	stream.read(
		bytes,
		std::ios_base::binary);

	BOOST_CHECK(
		bytes[0] == 'a');
	BOOST_CHECK(
		bytes[1] == 'b');
	BOOST_CHECK(
		bytes[2] == 'c');
	BOOST_CHECK(
		stream.eof());
}
