const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = env => {
  return {
    mode: env.development ? 'development' : 'production',
    entry: {
      index: "./src/index.js",
    },
    devtool: 'inline-source-map',
    devServer: {
      static: './dist',
    },
    plugins: [
      new HtmlWebpackPlugin({
        template: './src/index.html',
        favicon: './images/favicon.png',
        minify: false,
      }),
    ],
    output: {
      filename: "[name].bundle.js",
      path: path.resolve(__dirname, "dist"),
      clean: true,
    },
    optimization: {
      runtimeChunk: 'single',
    },
    module: {
      rules: [
        {
          test: /\.css$/i,
          use: ['style-loader', 'css-loader'],
        },
        {
          test: /\.s[ac]ss$/i,
          use: [
            "style-loader", // Creates `style` nodes from JS strings
            "css-loader", // Translates CSS into CommonJS
            "sass-loader", // Compiles Sass to CSS
          ],
        },
        {
          oneOf: [
            {
              test: /\.svg$/,
              type: "asset/inline",
            },
            {
              test: /\.(jpg|png|svg)$/,
              type: "asset/resource",
            },
          ]
        },
      ],
    },
  };
};
