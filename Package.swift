// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "WalletCore",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "WalletCore", targets: ["WalletCore"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "WalletCore",
            url: "https://github.com/trustwallet/wallet-core/releases/download/3.1.19/WalletCore.xcframework.zip",
            checksum: "0bd741c24ef1be4774359fc77a6680570c3bcd94a69d06e5c4596e4db8785ee6"
        )
    ]
)
