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
            url: "https://github.com/trustwallet/wallet-core/releases/download/3.1.8/WalletCore.xcframework.zip",
            checksum: "ce7e45a8eea666dacc5cd9076f597e4f824c030299414c7fdd91e71b29aa09cc"
        )
    ]
)
