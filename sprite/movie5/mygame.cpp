#include "mygame.h"

#define UPPER_BODY_X	0.015f
#define UPPER_BODY_Y	-0.065f
#define HEAD_X			-0.014f
#define HEAD_Y			-0.27f

MyGame::MyGame()
	: DemoBase()
{
}

MyGame::~MyGame()
{
}

BOOL MyGame::Initialize()
{
	DemoBase::Initialize();

	sptBody.Load("sprite/movie5/witchdoctor_body.sprite", &glDemoResources);
	sptBody.SetPriority(1);
	pRenderer->Add(&sptBody);

	sptUpperBody.Load("sprite/movie5/witchdoctor_upper_body.sprite", &glDemoResources);
	sptUpperBody.SetPriority(2);
	pRenderer->Add(&sptUpperBody);

	sptHead.Load("sprite/movie5/witchdoctor_head.sprite", &glDemoResources);
	sptHead.SetPriority(3);
	pRenderer->Add(&sptHead);

	tmBody.SetObject(&sptBody);
	tmUpperBody.SetObject(&sptUpperBody);
	tmHead.SetObject(&sptHead);

	//setup the keyframes
	//body
	kfBody[0].ptPos.x			= -0.04f;

	//upper body
	kfUpperBody[0].bTween		= TRUE;
	kfUpperBody[0].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[0].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[0].ptLocalPos.x = 0.03f;
	kfUpperBody[0].ptLocalPos.y = 0.05f;
	kfUpperBody[0].fRotation 	= -5.3f;
	kfUpperBody[0].fEasing 		= -1.0f;

	kfUpperBody[1].bTween		= TRUE;
	kfUpperBody[1].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[1].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[1].ptLocalPos.x = 0.03f;
	kfUpperBody[1].ptLocalPos.y = 0.05f;
	kfUpperBody[1].fEasing 		= 1.0f;

	kfUpperBody[2].bTween		= TRUE;
	kfUpperBody[2].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[2].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[2].ptLocalPos.x = 0.03f;
	kfUpperBody[2].ptLocalPos.y = 0.05f;
	kfUpperBody[2].fRotation 	= 5.3f;
	kfUpperBody[2].fEasing 		= -1.0f;

	kfUpperBody[3].bTween		= TRUE;
	kfUpperBody[3].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[3].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[3].ptLocalPos.x = 0.03f;
	kfUpperBody[3].ptLocalPos.y = 0.05f;
	kfUpperBody[3].fRotation 	= 5.3f;
	kfUpperBody[3].fEasing 		= -1.0f;

	kfUpperBody[4].bTween		= TRUE;
	kfUpperBody[4].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[4].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[4].ptLocalPos.x = 0.03f;
	kfUpperBody[4].ptLocalPos.y = 0.05f;
	kfUpperBody[4].fRotation 	= 0.0f;
	kfUpperBody[4].fEasing 		= 1.0f;

	kfUpperBody[5].bTween		= TRUE;
	kfUpperBody[5].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[5].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[5].ptLocalPos.x = 0.03f;
	kfUpperBody[5].ptLocalPos.y = 0.05f;
	kfUpperBody[5].fRotation 	= -5.3f;
	kfUpperBody[5].fEasing 		= -1.0f;

	kfUpperBody[6].bTween		= TRUE;
	kfUpperBody[6].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[6].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[6].ptLocalPos.x = 0.03f;
	kfUpperBody[6].ptLocalPos.y = 0.05f;
	kfUpperBody[6].fRotation 	= -5.3f;
	kfUpperBody[6].fEasing 		= 0.0f;

	kfUpperBody[7].bTween		= TRUE;
	kfUpperBody[7].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[7].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[7].ptLocalPos.x = 0.03f;
	kfUpperBody[7].ptLocalPos.y = 0.05f;
	kfUpperBody[7].fRotation 	= -5.3f;
	kfUpperBody[7].ptScale.y	= 1.11f;
	kfUpperBody[7].fEasing 		= 1.0f;

	kfUpperBody[8].bTween		= TRUE;
	kfUpperBody[8].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[8].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[8].ptLocalPos.x = 0.03f;
	kfUpperBody[8].ptLocalPos.y = 0.05f;
	kfUpperBody[8].fRotation 	= -5.3f;
	kfUpperBody[8].ptScale.y	= 1.22f;
	kfUpperBody[8].fEasing 		= 0.0f;

	kfUpperBody[9].bTween		= TRUE;
	kfUpperBody[9].ptPos.x 		= UPPER_BODY_X;
	kfUpperBody[9].ptPos.y 		= UPPER_BODY_Y;
	kfUpperBody[9].ptLocalPos.x = 0.03f;
	kfUpperBody[9].ptLocalPos.y = 0.05f;
	kfUpperBody[9].fRotation 	= -5.3f;
	kfUpperBody[9].ptScale.y	= 1.11f;
	kfUpperBody[9].fEasing 		= 1.0f;

	kfUpperBody[10].bTween		= TRUE;
	kfUpperBody[10].ptPos.x 	= UPPER_BODY_X;
	kfUpperBody[10].ptPos.y 	= UPPER_BODY_Y;
	kfUpperBody[10].ptLocalPos.x = 0.03f;
	kfUpperBody[10].ptLocalPos.y = 0.05f;
	kfUpperBody[10].fRotation 	= -5.3f;
	kfUpperBody[10].fEasing 	= 0.0f;

	kfUpperBody[11].bTween		= TRUE;
	kfUpperBody[11].ptPos.x 	= UPPER_BODY_X;
	kfUpperBody[11].ptPos.y 	= UPPER_BODY_Y;
	kfUpperBody[11].ptLocalPos.x = 0.03f;
	kfUpperBody[11].ptLocalPos.y = 0.05f;
	kfUpperBody[11].fRotation 	= -5.3f;
	kfUpperBody[11].fEasing 	= 0.0f;

	//head
	float fHeadPivotY			= (tmHead.GetHeight() / 2.0f) - 0.02f;
	Log("head: %f", fHeadPivotY);
	kfHead[0].bTween			= TRUE;
	kfHead[0].ptPos.x 			= HEAD_X;
	kfHead[0].ptPos.y 			= HEAD_Y;
	kfHead[0].ptLocalPos.y 		= fHeadPivotY;
	kfHead[0].fRotation 		= -8.1f;
	kfHead[0].fEasing 			= -1;

	kfHead[1].bTween			= TRUE;
	kfHead[1].ptPos.x 			= HEAD_X;
	kfHead[1].ptPos.y 			= HEAD_Y;
	kfHead[1].ptLocalPos.y 		= fHeadPivotY;
	kfHead[1].fRotation 		= 0.0f;
	kfHead[1].fEasing 			= 1;

	kfHead[2].bTween			= TRUE;
	kfHead[2].ptPos.x 			= HEAD_X;
	kfHead[2].ptPos.y 			= HEAD_Y;
	kfHead[2].ptLocalPos.y 		= fHeadPivotY;
	kfHead[2].fRotation 		= 9.1f;
	kfHead[2].fEasing 			= -1;

	kfHead[3].bTween			= TRUE;
	kfHead[3].ptPos.x 			= HEAD_X;
	kfHead[3].ptPos.y 			= HEAD_Y;
	kfHead[3].ptLocalPos.y 		= fHeadPivotY;
	kfHead[3].fRotation 		= 9.1f;
	kfHead[3].fEasing 			= -1;

	kfHead[4].bTween			= TRUE;
	kfHead[4].ptPos.x 			= HEAD_X;
	kfHead[4].ptPos.y 			= HEAD_Y;
	kfHead[4].ptLocalPos.y 		= fHeadPivotY;
	kfHead[4].fRotation 		= 5.6f;
	kfHead[4].fEasing 			= 1;

	kfHead[5].bTween			= TRUE;
	kfHead[5].ptPos.x 			= HEAD_X;
	kfHead[5].ptPos.y 			= HEAD_Y;
	kfHead[5].ptLocalPos.y 		= fHeadPivotY;
	kfHead[5].fRotation 		= -0.6f;
	kfHead[5].fEasing 			= -1;

	kfHead[6].bTween			= TRUE;
	kfHead[6].ptPos.x 			= HEAD_X;
	kfHead[6].ptPos.y 			= HEAD_Y;
	kfHead[6].ptLocalPos.y 		= fHeadPivotY;
	kfHead[6].fRotation 		= -0.6f;
	kfHead[6].fEasing 			= -1;

	kfHead[7].bTween			= TRUE;
	kfHead[7].ptPos.x 			= HEAD_X;
	kfHead[7].ptPos.y 			= HEAD_Y;
	kfHead[7].ptLocalPos.y 		= fHeadPivotY;
	kfHead[7].fRotation 		= 6.2f;
	kfHead[7].fEasing 			= 1;

	kfHead[8].bTween			= TRUE;
	kfHead[8].ptPos.x 			= HEAD_X;
	kfHead[8].ptPos.y 			= HEAD_Y;
	kfHead[8].ptLocalPos.y 		= fHeadPivotY;
	kfHead[8].fRotation 		= 9.1f;
	kfHead[8].fEasing 			= -1;

	kfHead[9].bTween			= TRUE;
	kfHead[9].ptPos.x 			= HEAD_X;
	kfHead[9].ptPos.y 			= HEAD_Y;
	kfHead[9].ptLocalPos.y 		= fHeadPivotY;
	kfHead[9].fRotation 		= 9.1f;
	kfHead[9].fEasing 			= -1;

	kfHead[10].bTween			= TRUE;
	kfHead[10].ptPos.x 			= HEAD_X;
	kfHead[10].ptPos.y 			= HEAD_Y;
	kfHead[10].ptLocalPos.y 	= fHeadPivotY;
	kfHead[10].fRotation 		= 0;
	kfHead[10].fEasing 			= 1;

	kfHead[11].bTween			= TRUE;
	kfHead[11].ptPos.x 			= HEAD_X;
	kfHead[11].ptPos.y 			= HEAD_Y;
	kfHead[11].ptLocalPos.y 	= fHeadPivotY;
	kfHead[11].fRotation 		= -8.3f;
	kfHead[11].fEasing 			= -1;

	kfHead[12].bTween			= TRUE;
	kfHead[12].ptPos.x 			= HEAD_X;
	kfHead[12].ptPos.y 			= HEAD_Y;
	kfHead[12].ptLocalPos.y 	= fHeadPivotY;
	kfHead[12].fRotation 		= -8.3f;
	kfHead[12].fEasing 			= 0;

	kfHead[13].bTween			= TRUE;
	kfHead[13].ptPos.x 			= HEAD_X;
	kfHead[13].ptPos.y 			= HEAD_Y - 0.01f;
	kfHead[13].ptLocalPos.y 	= fHeadPivotY;
	kfHead[13].fRotation 		= -8.3f;
	kfHead[13].fEasing 			= 1;

	kfHead[14].bTween			= TRUE;
	kfHead[14].ptPos.x 			= HEAD_X;
	kfHead[14].ptPos.y 			= HEAD_Y - 0.02f;
	kfHead[14].ptLocalPos.y 	= fHeadPivotY;
	kfHead[14].fRotation 		= -8.3f;
	kfHead[14].fEasing 			= 0;

	kfHead[15].bTween			= TRUE;
	kfHead[15].ptPos.x 			= HEAD_X;
	kfHead[15].ptPos.y 			= HEAD_Y - 0.01f;
	kfHead[15].ptLocalPos.y 	= fHeadPivotY;
	kfHead[15].fRotation 		= -8.3f;
	kfHead[15].fEasing 			= 1;

	kfHead[16].bTween			= TRUE;
	kfHead[16].ptPos.x 			= HEAD_X;
	kfHead[16].ptPos.y 			= HEAD_Y;
	kfHead[16].ptLocalPos.y 	= fHeadPivotY;
	kfHead[16].fRotation 		= -8.3f;
	kfHead[16].fEasing 			= 0;

	kfHead[17].bTween			= TRUE;
	kfHead[17].ptPos.x 			= HEAD_X;
	kfHead[17].ptPos.y 			= HEAD_Y;
	kfHead[17].ptLocalPos.y 	= fHeadPivotY;
	kfHead[17].fRotation 		= -8.3f;
	kfHead[17].fEasing 			= 0;

	//setup the timeline
	//body
	tmBody.AddKeyframe(0, &kfBody[0]);
	tmBody.AddKeyframe(416, &kfBody[0]);


	//upper body
	tmUpperBody.AddKeyframe(0, &kfUpperBody[0]);
	tmUpperBody.AddKeyframe(21, &kfUpperBody[1]);
	tmUpperBody.AddKeyframe(44, &kfUpperBody[2]);
	tmUpperBody.AddKeyframe(207, &kfUpperBody[3]);
	tmUpperBody.AddKeyframe(226, &kfUpperBody[4]);
	tmUpperBody.AddKeyframe(245, &kfUpperBody[5]);
	tmUpperBody.AddKeyframe(271, &kfUpperBody[6]);
	tmUpperBody.AddKeyframe(285, &kfUpperBody[7]);
	tmUpperBody.AddKeyframe(299, &kfUpperBody[8]);
	tmUpperBody.AddKeyframe(334, &kfUpperBody[9]);
	tmUpperBody.AddKeyframe(369, &kfUpperBody[10]);
	tmUpperBody.AddKeyframe(415, &kfUpperBody[11]);


	//head
	tmHead.AddKeyframe(0, &kfHead[0]);
	tmHead.AddKeyframe(21, &kfHead[1]);
	tmHead.AddKeyframe(44, &kfHead[2]);
	tmHead.AddKeyframe(75, &kfHead[3]);
	tmHead.AddKeyframe(89, &kfHead[4]);
	tmHead.AddKeyframe(102, &kfHead[5]);
	tmHead.AddKeyframe(117, &kfHead[6]);
	tmHead.AddKeyframe(141, &kfHead[7]);
	tmHead.AddKeyframe(168, &kfHead[8]);
	tmHead.AddKeyframe(207, &kfHead[9]);
	tmHead.AddKeyframe(226, &kfHead[10]);
	tmHead.AddKeyframe(245, &kfHead[11]);
	tmHead.AddKeyframe(271, &kfHead[12]);
	tmHead.AddKeyframe(285, &kfHead[13]);
	tmHead.AddKeyframe(299, &kfHead[14]);
	tmHead.AddKeyframe(334, &kfHead[15]);
	tmHead.AddKeyframe(369, &kfHead[16]);
	tmHead.AddKeyframe(415, &kfHead[17]);
	tmHead.SetListener(this);

	//movie
	movie.AddTimeline(&tmBody);
	movie.AddTimeline(&tmUpperBody);
	movie.AddTimeline(&tmHead);
	movie.SetPosition(0.2f, 0.5f);
	pRenderer->Add(&movie);

	return TRUE;
}

void MyGame::OnTimelineFrame(const EventMovie *ev)
{
	if ((ev->GetFrame() % 17) == 0)
		Log("Current frame: %d", ev->GetFrame());
}

void MyGame::OnTimelineRestart(const EventMovie *ev)
{
	Log("TIMELINE LOOPED");
}
