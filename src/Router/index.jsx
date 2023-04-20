import React, { Component } from "react";
import Process from "../Components/Process.tsx";
import Statisic from "../Components/Statistic.tsx";
import Calendar from "../Components/Calendar.tsx";
// import NaviTop from "../Components/NaviTop.tsx";
export default class index extends Component {
  render() {
    return (
      <>
        <div className="FLEX COL">
          <div className="FLEX ROW">
            <div className="MARGIN">
              <Calendar />
            </div>
            <div className="MARGIN">
              <div>
                <Process />
              </div>
              <div>
                <Statisic />
              </div>
            </div>
          </div>
        </div>
      </>
    );
  }
}
