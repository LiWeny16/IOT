// import type { CountdownProps } from "antd";
import { Col, Row, Statistic } from "antd";



const App: React.FC = (props:any) => (
  <>
    <Row>
      <Col>
        <div className="BORDER FLEX MARGIN">
          <Statistic className="MARGIN" title="HUMAN_1" value={props.dataAll[0][3]} />
          <Statistic className="MARGIN" title="HUMAN_2" value={props.dataAll[0][4]} / >
        </div>
        <div className="MARGIN">
        <Statistic className="MARGIN" title="ALL EN" value={props.dataAll[0][5]} / >
        </div>
      </Col>
    </Row>
  </>
);

export default App;

// 红外展示状态卡片
