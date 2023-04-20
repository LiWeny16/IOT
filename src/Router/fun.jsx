import React, { Component } from "react";
// import FloatBtn from "../Components/FloatButton"
import Cube from "../Components/three.js/cube";
export default class fun extends Component {
  render() {
    return (
      <>
        <div><p className="P2">神奇魔方</p></div>
        <div className="cube">
          <Cube />
        </div>
      </>
    );
  }
}
