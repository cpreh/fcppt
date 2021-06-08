let pkgs = import <nixpkgs> {};
    stdenv = pkgs.gcc10Stdenv;
in stdenv.mkDerivation rec {
  name = "fcppt-master";

  src = ./.;

  nativeBuildInputs = [ pkgs.cmake ];
  buildInputs = [ pkgs.boost pkgs.catch2 pkgs.metal ];

  cmakeFlags = [ "-DCMAKE_SKIP_BUILD_RPATH=false" "-DENABLE_BOOST=true" "-DENABLE_EXAMPLES=true" "-DENABLE_CATCH=true" "-DENABLE_TEST=true" ];

  enableParallelBuilding = true;

  doCheck = true;

  meta = with pkgs.lib; {
    description = "Freundlich's C++ toolkit";
    longDescription = ''
      Freundlich's C++ Toolkit (fcppt) is a collection of libraries that aim to improve general C++ code through better typing and functional programming.
    '';
    homepage = https://fcppt.org;
    license = licenses.boost;
    maintainers = with maintainers; [ pmiddend ];
    platforms = platforms.linux;
  };
}
