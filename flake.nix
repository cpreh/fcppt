{
  inputs = {
    nixpkgs.url = "nixpkgs/nixos-unstable-small";
  };

  outputs =
    { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
      buildenv =
        { stdenv }:
        import ./package.nix {
          inherit pkgs;
          inherit stdenv;
        };
    in
    {
      packages.${system} = {
        fcppt-clang21 = buildenv { stdenv = pkgs.llvmPackages_21.stdenv; };
        fcppt-gcc15 = buildenv { stdenv = pkgs.gcc15Stdenv; };
      };
    };
}
